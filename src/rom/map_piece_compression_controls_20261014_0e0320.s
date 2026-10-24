.setcpu "65816"
.segment "CODE"
.org $0320
map_control_0e0320:
    .byte $EE ; backreference distance high bits
    .byte $8A ; distance low bit/count
    .byte $C6 ; same-value copy count/distance
