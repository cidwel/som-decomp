.setcpu "65816"
.segment "CODE"
.org $82A8
map_control_0f82a8:
    .byte $E9 ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $C5 ; same-value copy count/distance
    .byte $EE ; backreference distance high bits
    .byte $89 ; distance low bit/count
