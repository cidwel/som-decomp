.setcpu "65816"
.segment "CODE"
.org $106E
map_control_0f106e:
    .byte $F2 ; progressive-copy count
    .byte $EE ; backreference distance high bits
    .byte $97 ; distance low bit/count
    .byte $C1 ; same-value copy count/distance
