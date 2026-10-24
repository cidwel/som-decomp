.setcpu "65816"
.segment "CODE"
.org $9364
map_control_0e9364:
    .byte $C7 ; same-value copy count/distance
    .byte $EF ; backreference distance high bits
    .byte $03 ; distance low bit/count
