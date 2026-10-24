.setcpu "65816"
.segment "CODE"
.org $B168
map_control_0fb168:
    .byte $E9 ; backreference distance high bits
    .byte $87 ; distance low bit/count
    .byte $E5 ; previous-row copy count
    .byte $C4 ; same-value copy count/distance
