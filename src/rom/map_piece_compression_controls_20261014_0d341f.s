.setcpu "65816"
.segment "CODE"
.org $341F
map_control_0d341f:
    .byte $C9 ; same-value copy count/distance
    .byte $ED ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $0E ; distance low bit/count
