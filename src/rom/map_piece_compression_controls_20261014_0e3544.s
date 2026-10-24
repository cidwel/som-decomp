.setcpu "65816"
.segment "CODE"
.org $3544
map_control_0e3544:
    .byte $D2 ; same-value copy count/distance
    .byte $E9 ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $88 ; row-distance/count
    .byte $C3 ; same-value copy count/distance
