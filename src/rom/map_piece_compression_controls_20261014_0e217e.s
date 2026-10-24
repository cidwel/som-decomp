.setcpu "65816"
.segment "CODE"
.org $217E
map_control_0e217e:
    .byte $EE ; backreference distance high bits
    .byte $88 ; distance low bit/count
    .byte $C2 ; same-value copy count/distance
