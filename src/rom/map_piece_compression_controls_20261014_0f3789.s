.setcpu "65816"
.segment "CODE"
.org $3789
map_control_0f3789:
    .byte $C2 ; same-value copy count/distance
    .byte $EE ; backreference distance high bits
    .byte $88 ; distance low bit/count
