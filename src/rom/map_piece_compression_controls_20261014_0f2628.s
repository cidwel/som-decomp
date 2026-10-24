.setcpu "65816"
.segment "CODE"
.org $2628
map_control_0f2628:
    .byte $EE ; backreference distance high bits
    .byte $84 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $19 ; distance low bit/count
