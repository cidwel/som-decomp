"""Declared decoded resource references; resource payloads stay in memory."""
import boot_decode


def declarations(manifest):
    resources = {}
    for row in manifest.get('decoded_resources', []):
        name = row['reference']
        source = int(row['source_address'], 16)
        destination = int(row['destination_address'], 16)
        size = row['output_size']
        if name in resources or name in ('rom', 'decoded_boot_program'):
            raise ValueError('Duplicate or reserved decoded resource reference')
        if destination >> 16 != 0x7E or not 0 < size <= 0x10000 - (destination & 0xFFFF):
            raise ValueError('Decoded resource must fit within WRAM bank 7E')
        resources[name] = dict(row, source=source, destination=destination)
    return resources


def images(rom, manifest):
    memory, _ = boot_decode.decode(rom, boot_decode.BOOT_SOURCE, boot_decode.BOOT_DEST)
    result = {'decoded_boot_program': memory}
    for name, row in declarations(manifest).items():
        memory, info = boot_decode.decode(rom, row['source'], row['destination'])
        if info['output_size'] != row['output_size'] or info['produced_size'] != row['output_size']:
            raise ValueError('Decoded resource size differs from its declared extent')
        result[name] = memory
    return result


def check_block(block, resources):
    reference = block['reference']
    address = int(block['address'], 16)
    if reference == 'rom':
        return
    if reference == 'decoded_boot_program':
        if address >> 16 != 0x7E:
            raise ValueError('Decoded boot source must use WRAM bank 7E')
        return
    row = resources[reference]
    if not row['destination'] <= address < address + block['size'] <= row['destination'] + row['output_size']:
        raise ValueError('Source block exceeds its declared decoded resource')
