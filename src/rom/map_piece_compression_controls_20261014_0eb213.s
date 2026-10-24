.setcpu "65816"
.segment "CODE"
.org $B213
map_control_0eb213:
    .byte $E8 ; backreference distance high bits
    .byte $0A ; distance low bit/count
