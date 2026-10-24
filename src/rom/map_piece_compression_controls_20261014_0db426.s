.setcpu "65816"
.segment "CODE"
.org $B426
map_control_0db426:
    .byte $C9 ; same-value copy count/distance
    .byte $ED ; backreference distance high bits
    .byte $87 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $1D ; row-distance/count
