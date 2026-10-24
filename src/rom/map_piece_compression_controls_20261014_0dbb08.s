.setcpu "65816"
.segment "CODE"
.org $BB08
map_control_0dbb08:
    .byte $EF ; backreference distance high bits
    .byte $88 ; distance low bit/count
    .byte $C5 ; same-value copy count/distance
