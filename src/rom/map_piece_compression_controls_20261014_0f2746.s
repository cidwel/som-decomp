.setcpu "65816"
.segment "CODE"
.org $2746
map_control_0f2746:
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
    .byte $C2 ; same-value copy count/distance
