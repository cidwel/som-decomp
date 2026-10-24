.setcpu "65816"
.segment "CODE"
.org $C56B
map_control_0dc56b:
    .byte $E0 ; previous-row copy escape
    .byte $13 ; row-distance/count
    .byte $C1 ; same-value copy count/distance
