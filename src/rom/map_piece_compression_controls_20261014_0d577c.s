.setcpu "65816"
.segment "CODE"
.org $577C
map_control_0d577c:
    .byte $ED ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $C2 ; same-value copy count/distance
