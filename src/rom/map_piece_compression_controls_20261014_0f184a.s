.setcpu "65816"
.segment "CODE"
.org $184A
map_control_0f184a:
    .byte $EF ; backreference distance high bits
    .byte $09 ; distance low bit/count
    .byte $C3 ; same-value copy count/distance
