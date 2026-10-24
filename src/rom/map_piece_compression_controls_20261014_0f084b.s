.setcpu "65816"
.segment "CODE"
.org $084B
map_control_0f084b:
    .byte $E8 ; backreference distance high bits
    .byte $83 ; distance low bit/count
