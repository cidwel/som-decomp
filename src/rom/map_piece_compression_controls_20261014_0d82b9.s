.setcpu "65816"
.segment "CODE"
.org $82B9
map_control_0d82b9:
    .byte $E0 ; previous-row copy escape
    .byte $11 ; row-distance/count
    .byte $C4 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $1E ; row-distance/count
