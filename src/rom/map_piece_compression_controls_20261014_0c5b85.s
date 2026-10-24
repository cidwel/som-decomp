.setcpu "65816"
.segment "CODE"
.org $5B85
map_control_0c5b85:
    .byte $C4 ; same-value copy count/distance
    .byte $ED ; backreference distance high bits
    .byte $86 ; distance low bit/count
