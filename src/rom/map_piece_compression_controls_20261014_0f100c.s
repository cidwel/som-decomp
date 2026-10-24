.setcpu "65816"
.segment "CODE"
.org $100C
map_control_0f100c:
    .byte $E8 ; backreference distance high bits
    .byte $0A ; distance low bit/count
