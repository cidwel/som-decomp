.setcpu "65816"
.segment "CODE"
.org $3E4C
map_control_0f3e4c:
    .byte $C4 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $3F ; row-distance/count
