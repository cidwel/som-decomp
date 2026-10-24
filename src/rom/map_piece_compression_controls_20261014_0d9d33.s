.setcpu "65816"
.segment "CODE"
.org $9D33
map_control_0d9d33:
    .byte $E8 ; backreference distance high bits
    .byte $88 ; distance low bit/count
