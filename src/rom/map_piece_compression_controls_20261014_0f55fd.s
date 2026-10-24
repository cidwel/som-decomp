.setcpu "65816"
.segment "CODE"
.org $55FD
map_control_0f55fd:
    .byte $EC ; backreference distance high bits
    .byte $86 ; distance low bit/count
    .byte $C2 ; same-value copy count/distance
