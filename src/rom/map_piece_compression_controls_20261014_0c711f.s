.setcpu "65816"
.segment "CODE"
.org $711F
map_control_0c711f:
    .byte $EB ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $C3 ; same-value copy count/distance
    .byte $EF ; backreference distance high bits
    .byte $82 ; distance low bit/count
