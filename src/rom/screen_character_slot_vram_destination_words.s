; Numeric slot destination indices; docs/event-screen-tile-reload.md.
.setcpu "65816"
.segment "CODE"
.org $7F35
screen_character_slot_vram_destination_words:
    .word $000A, $000C, $000E, $0020, $0022, $0024, $0026, $0028
    .word $002A, $002C, $002E, $0040, $0042, $0044, $0046, $0048
    .word $004A, $004C, $004E, $0060, $0062, $0064, $0066, $0068
    .word $006A, $006C, $006E, $0080, $0082, $0084, $0086, $0088
    .word $008A, $008C, $008E, $00A0, $00A2, $00A4, $00A6, $00A8
    .word $00AA, $00AC, $00AE, $00C0, $00C2, $00C4, $00C6, $00C8
    .word $00CA, $00CC, $00CE, $00E0, $00E2, $00E4, $00E6, $00E8
    .word $00EA, $00EC, $00EE, $0100, $0102, $0104, $0106, $0108
    .word $010A, $010C, $010E, $0120, $0122, $0124, $0126, $0128
    .word $012A, $012C, $012E, $0140, $0142
