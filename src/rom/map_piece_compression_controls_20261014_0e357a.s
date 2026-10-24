.setcpu "65816"
.segment "CODE"
.org $357A
map_control_0e357a:
    .byte $EE ; backreference distance high bits
    .byte $88 ; distance low bit/count
    .byte $C4 ; same-value copy count/distance
