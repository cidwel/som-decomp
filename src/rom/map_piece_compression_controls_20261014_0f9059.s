.setcpu "65816"
.segment "CODE"
.org $9059
map_control_0f9059:
    .byte $EF ; backreference distance high bits
    .byte $04 ; distance low bit/count
    .byte $C1 ; same-value copy count/distance
