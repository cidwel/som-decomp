.setcpu "65816"
.segment "CODE"
.org $DFCC
map_control_0fdfcc:
    .byte $E8 ; backreference distance high bits
    .byte $0A ; distance low bit/count
