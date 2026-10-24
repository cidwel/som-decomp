.setcpu "65816"
.segment "CODE"
.org $0FF3
map_control_0f0ff3:
    .byte $E0 ; previous-row copy escape
    .byte $27 ; row-distance/count
    .byte $C2 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $0E ; row-distance/count
    .byte $C2 ; same-value copy count/distance
    .byte $E7 ; previous-row copy count
    .byte $E8 ; backreference distance high bits
    .byte $09 ; distance low bit/count
    .byte $E7 ; previous-row copy count
    .byte $C6 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $1E ; row-distance/count
