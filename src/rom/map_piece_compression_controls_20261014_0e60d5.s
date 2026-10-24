.setcpu "65816"
.segment "CODE"
.org $60D5
map_control_0e60d5:
    .byte $EE ; backreference distance high bits
    .byte $03 ; distance low bit/count
    .byte $C3 ; same-value copy count/distance
