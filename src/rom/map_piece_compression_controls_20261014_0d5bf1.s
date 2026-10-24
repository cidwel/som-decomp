.setcpu "65816"
.segment "CODE"
.org $5BF1
map_control_0d5bf1:
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
    .byte $C9 ; same-value copy count/distance
