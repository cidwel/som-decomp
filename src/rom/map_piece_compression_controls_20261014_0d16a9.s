.setcpu "65816"
.segment "CODE"
.org $16A9
map_control_0d16a9:
    .byte $E8 ; backreference distance high bits
    .byte $82 ; distance low bit/count
