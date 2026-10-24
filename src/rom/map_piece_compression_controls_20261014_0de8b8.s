.setcpu "65816"
.segment "CODE"
.org $E8B8
map_control_0de8b8:
    .byte $C1 ; same-value copy count/distance
    .byte $ED ; backreference distance high bits
    .byte $03 ; distance low bit/count
