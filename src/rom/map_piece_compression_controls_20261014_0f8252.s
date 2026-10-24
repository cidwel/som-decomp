.setcpu "65816"
.segment "CODE"
.org $8252
map_control_0f8252:
    .byte $E9 ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $C5 ; same-value copy count/distance
    .byte $EE ; backreference distance high bits
    .byte $88 ; distance low bit/count
