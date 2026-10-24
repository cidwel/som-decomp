.setcpu "65816"
.segment "CODE"
.org $E0D6
map_control_0de0d6:
    .byte $EF ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $C7 ; same-value copy count/distance
