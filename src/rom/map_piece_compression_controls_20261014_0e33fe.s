.setcpu "65816"
.segment "CODE"
.org $33FE
map_control_0e33fe:
    .byte $C1 ; same-value copy count/distance
    .byte $ED ; backreference distance high bits
    .byte $83 ; distance low bit/count
