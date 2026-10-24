.setcpu "65816"
.segment "CODE"
.org $4AA8
map_control_0d4aa8:
    .byte $C6 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $D2 ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $B3 ; row-distance/count
