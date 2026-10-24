.setcpu "65816"
.segment "CODE"
.org $ED1F
map_control_0fed1f:
    .byte $EF ; backreference distance high bits
    .byte $8A ; distance low bit/count
    .byte $C3 ; same-value copy count/distance
