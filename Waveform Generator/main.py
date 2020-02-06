source_file = 'audacity.wav'
sample_name = 'wav1'
sample_points = 100
output_file = '0'

def format_name(name):
    name = name.ljust(16)

    name = name[0:16]

    return name


# Ensure that input file is single channel signed 16-bit PCM
# If so, return the actual data

def parse_header(entire):
    splitter = 'data'
    splitter = splitter.encode('ASCII')
    sections = entire.split(splitter)

    header = sections[0]

    fmt_chk = header[16:]

    format = (fmt_chk[3] << 8) + fmt_chk[4]
    channels = (fmt_chk[5] << 8) + fmt_chk[6]

    if format != 1:
        print("Wrong format")

    if channels > 1:
        print("Too many channels")

    content = sections[1][4:]

    return content


# Convert signed 16-bit PCM to 8-bit unsigned PCM

def decode(entire):
    out_vals = []

    it = iter(entire)
    for byte in it:
        next_byte = next(it)

        # Combine msb and lsb
        msb = byte & 0xff
        lsb = next_byte << 8
        full_number = int(lsb | msb)

        # Remove sign bit
        base = full_number & 0x7FFF

        # If sign bit set, make base negative
        if full_number & 0x8000:
            base -= 0x8000

        # Reduce 16 bit signed to 8 bit signed
        base = int(base / 2**8)

        # Shift value to be unsigned
        base += 127
        out_vals.append(base)

    return out_vals


# Reduce input samples down to num_samples of samples

def consolidate(values, num_samples):

    num_input = len(values)

    dividor = num_input / num_samples

    all_points = values[::int(dividor)]

    if len(all_points) != num_samples:
        all_points = values[int(dividor/2)::int(dividor)]
    else:
        return all_points

    if len(all_points) != num_samples:
        all_points = values[int(3 * dividor / 4)::int(dividor)]

    if len(all_points) != num_samples:
        all_points = values[int(dividor / 2) - 1:-int(dividor / 2):int(dividor)]

    if len(all_points) != num_samples:
        all_points = values[int(3 * dividor / 4) - 1:-int(3 * dividor / 4):int(dividor)]

    return all_points


with open(source_file, 'rb') as f:
    entire = f.read()

# Remove header
body = parse_header(entire)

# 16-bit signed PCM to 8-bit unsigned PCM
vals = decode(body)

# Reduce down to 100 samples
vals = consolidate(vals, sample_points)

# Metadata field name
name = format_name(sample_name).encode('UTF-8')

# Metadata field length
length = bytes([len(vals)])

vals = bytes(vals)

# Add metadata to packet
vals = name + length + vals

# Write out file
with open(output_file, "wb") as f:
       f.write(vals)
