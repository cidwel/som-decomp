.setcpu "65816"
.segment "CODE"
.org $5973
map_control_0d5973:
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $1A ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $CC ; row-distance/count
    .byte $C2 ; same-value copy count/distance
