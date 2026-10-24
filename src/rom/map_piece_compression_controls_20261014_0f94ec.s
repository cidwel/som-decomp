.setcpu "65816"
.segment "CODE"
.org $94EC
map_control_0f94ec:
    .byte $EF ; backreference distance high bits
    .byte $07 ; distance low bit/count
    .byte $EE ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $C5 ; same-value copy count/distance
