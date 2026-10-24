.setcpu "65816"
.segment "CODE"
.org $2953
map_control_0f2953:
    .byte $C5 ; same-value copy count/distance
    .byte $E2 ; previous-row copy count
    .byte $DA ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $22 ; row-distance/count
    .byte $C5 ; same-value copy count/distance
