.setcpu "65816"
.segment "CODE"
.org $86D2
map_control_0d86d2:
    .byte $C1 ; same-value copy count/distance
    .byte $ED ; backreference distance high bits
    .byte $03 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $17 ; distance low bit/count
