.setcpu "65816"
.segment "CODE"
.org $BB03
map_control_0ebb03:
    .byte $C2 ; same-value copy count/distance
    .byte $ED ; backreference distance high bits
    .byte $86 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $85 ; distance low bit/count
