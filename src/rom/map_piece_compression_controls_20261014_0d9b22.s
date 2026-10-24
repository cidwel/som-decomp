.setcpu "65816"
.segment "CODE"
.org $9B22
map_control_0d9b22:
    .byte $E8 ; backreference distance high bits
    .byte $98 ; distance low bit/count
    .byte $C4 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $88 ; row-distance/count
