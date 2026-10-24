.setcpu "65816"
.segment "CODE"
.org $823E
map_control_0f823e:
    .byte $E9 ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $C5 ; same-value copy count/distance
    .byte $EE ; backreference distance high bits
    .byte $88 ; distance low bit/count
