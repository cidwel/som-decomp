.setcpu "65816"
.segment "CODE"
.org $26B5
map_control_0f26b5:
    .byte $EE ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $C5 ; same-value copy count/distance
