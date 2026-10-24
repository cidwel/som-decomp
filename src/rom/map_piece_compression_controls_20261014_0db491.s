.setcpu "65816"
.segment "CODE"
.org $B491
map_control_0db491:
    .byte $EF ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $C7 ; same-value copy count/distance
