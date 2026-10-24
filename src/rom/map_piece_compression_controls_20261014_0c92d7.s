.setcpu "65816"
.segment "CODE"
.org $92D7
map_control_0c92d7:
    .byte $EE ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $C4 ; same-value copy count/distance
