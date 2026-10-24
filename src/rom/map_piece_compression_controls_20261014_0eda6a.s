.setcpu "65816"
.segment "CODE"
.org $DA6A
map_control_0eda6a:
    .byte $E9 ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $C9 ; same-value copy count/distance
    .byte $EC ; backreference distance high bits
    .byte $87 ; distance low bit/count
