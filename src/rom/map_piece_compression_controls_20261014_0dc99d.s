.setcpu "65816"
.segment "CODE"
.org $C99D
map_control_0dc99d:
    .byte $C2 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
