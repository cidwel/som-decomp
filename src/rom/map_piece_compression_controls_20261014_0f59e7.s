.setcpu "65816"
.segment "CODE"
.org $59E7
map_control_0f59e7:
    .byte $EE ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $C3 ; same-value copy count/distance
