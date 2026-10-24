.setcpu "65816"
.segment "CODE"
.org $71AD
map_control_0e71ad:
    .byte $EF ; backreference distance high bits
    .byte $04 ; distance low bit/count
    .byte $C3 ; same-value copy count/distance
