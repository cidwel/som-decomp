.setcpu "65816"
.segment "CODE"
.org $5B53
map_control_0c5b53:
    .byte $C4 ; same-value copy count/distance
    .byte $ED ; backreference distance high bits
    .byte $86 ; distance low bit/count
