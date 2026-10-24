.setcpu "65816"
.segment "CODE"
.org $4782
map_control_0d4782:
    .byte $E8 ; backreference distance high bits
    .byte $88 ; distance low bit/count
