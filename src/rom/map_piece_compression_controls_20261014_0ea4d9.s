.setcpu "65816"
.segment "CODE"
.org $A4D9
map_control_0ea4d9:
    .byte $E6 ; previous-row copy count
    .byte $E8 ; backreference distance high bits
    .byte $10 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $1D ; row-distance/count
    .byte $C2 ; same-value copy count/distance
