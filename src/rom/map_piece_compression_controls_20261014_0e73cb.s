.setcpu "65816"
.segment "CODE"
.org $73CB
map_control_0e73cb:
    .byte $E8 ; backreference distance high bits
    .byte $90 ; distance low bit/count
