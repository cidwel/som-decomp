.setcpu "65816"
.segment "CODE"
.org $2003
map_control_0f2003:
    .byte $EE ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $C5 ; same-value copy count/distance
