.setcpu "65816"
.segment "CODE"
.org $B659
map_control_0db659:
    .byte $C2 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $8D ; row-distance/count
