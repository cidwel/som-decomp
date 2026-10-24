.setcpu "65816"
.segment "CODE"
.org $182B
map_control_0f182b:
    .byte $EE ; backreference distance high bits
    .byte $07 ; distance low bit/count
    .byte $C5 ; same-value copy count/distance
