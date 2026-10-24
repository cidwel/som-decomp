.setcpu "65816"
.segment "CODE"
.org $82E9
map_control_0d82e9:
    .byte $E0 ; previous-row copy escape
    .byte $10 ; row-distance/count
    .byte $C6 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $1E ; row-distance/count
