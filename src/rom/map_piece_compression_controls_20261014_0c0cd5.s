.setcpu "65816"
.segment "CODE"
.org $0CD5
map_control_0c0cd5:
    .byte $C1 ; same-value copy count/distance
    .byte $EE ; backreference distance high bits
    .byte $86 ; distance low bit/count
    .byte $C6 ; same-value copy count/distance
