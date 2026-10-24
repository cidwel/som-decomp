.setcpu "65816"
.segment "CODE"
.org $86F1
map_control_0e86f1:
    .byte $C1 ; same-value copy count/distance
    .byte $EE ; backreference distance high bits
    .byte $87 ; distance low bit/count
