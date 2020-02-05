def get_name():
    name = "1234"

    name = name.ljust(16)

    name = name[0:16]

    return name


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


def decode(entire):
    out_vals = []

    it = iter(entire)
    for byte in it:
        next_byte = next(it)

        msb = byte & 0xff
        lsb = next_byte << 8
        full_number = int(lsb | msb)

        base = full_number & 0x7FFF

        if full_number & 0x8000:
            base -= 0x8000

        base = int(base / 2**8)

        base += 127
        out_vals.append(base)

    return out_vals


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


with open('audacity.wav', 'rb') as f:
    entire = f.read()

body = parse_header(entire)
vals = decode(body)

vals = consolidate(vals, 100)

name = get_name().encode('UTF-8')

length = bytes([len(vals)])

vals = bytes(vals)

vals = name + length + vals

with open('out', "wb") as f:
       f.write(vals)
