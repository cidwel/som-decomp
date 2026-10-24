.setcpu "65816"
.segment "CODE"
.org $86C6
map_control_0f86c6:
    .byte $C2 ; same-value copy count/distance
    .byte $EB ; backreference distance high bits
    .byte $03 ; distance low bit/count
