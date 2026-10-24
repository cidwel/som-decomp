.setcpu "65816"
.segment "CODE"
.org $ED3A
map_control_0fed3a:
    .byte $C4 ; same-value copy count/distance
    .byte $EE ; backreference distance high bits
    .byte $83 ; distance low bit/count
