.setcpu "65816"
.segment "CODE"
.org $6BBB
map_control_0d6bbb:
    .byte $DF ; same-value copy count/distance
    .byte $EF ; backreference distance high bits
    .byte $09 ; distance low bit/count
