.setcpu "65816"
.segment "CODE"
.org $DCC5
map_control_0edcc5:
    .byte $D2 ; same-value copy count/distance
    .byte $E9 ; backreference distance high bits
    .byte $87 ; distance low bit/count
    .byte $EA ; backreference distance high bits
    .byte $87 ; distance low bit/count
