.setcpu "65816"
.segment "CODE"
.org $1054
map_control_0f1054:
    .byte $F2 ; progressive-copy count
    .byte $EE ; backreference distance high bits
    .byte $97 ; distance low bit/count
    .byte $C1 ; same-value copy count/distance
