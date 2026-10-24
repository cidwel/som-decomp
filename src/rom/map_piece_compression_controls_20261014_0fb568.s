.setcpu "65816"
.segment "CODE"
.org $B568
map_control_0fb568:
    .byte $E9 ; backreference distance high bits
    .byte $04 ; distance low bit/count
    .byte $C5 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
