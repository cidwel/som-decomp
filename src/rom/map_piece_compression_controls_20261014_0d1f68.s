.setcpu "65816"
.segment "CODE"
.org $1F68
map_control_0d1f68:
    .byte $E8 ; backreference distance high bits
    .byte $88 ; distance low bit/count
