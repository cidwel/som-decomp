.setcpu "65816"
.segment "CODE"
.org $AE45
map_control_0dae45:
    .byte $E9 ; backreference distance high bits
    .byte $04 ; distance low bit/count
    .byte $C3 ; same-value copy count/distance
