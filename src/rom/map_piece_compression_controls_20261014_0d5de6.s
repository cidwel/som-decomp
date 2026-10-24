.setcpu "65816"
.segment "CODE"
.org $5DE6
map_control_0d5de6:
    .byte $C1 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $1F ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
    .byte $E4 ; previous-row copy count
    .byte $C1 ; same-value copy count/distance
