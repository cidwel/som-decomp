.setcpu "65816"
.segment "CODE"
.org $8D07
map_control_0e8d07:
    .byte $EE ; backreference distance high bits
    .byte $04 ; distance low bit/count
    .byte $D2 ; same-value copy count/distance
