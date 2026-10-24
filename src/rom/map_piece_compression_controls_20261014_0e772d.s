.setcpu "65816"
.segment "CODE"
.org $772D
map_control_0e772d:
    .byte $EF ; backreference distance high bits
    .byte $04 ; distance low bit/count
    .byte $C5 ; same-value copy count/distance
