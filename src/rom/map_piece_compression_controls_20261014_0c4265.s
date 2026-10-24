.setcpu "65816"
.segment "CODE"
.org $4265
map_control_0c4265:
    .byte $EC ; backreference distance high bits
    .byte $04 ; distance low bit/count
    .byte $C1 ; same-value copy count/distance
