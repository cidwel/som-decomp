.setcpu "65816"
.segment "CODE"
.org $57A3
map_control_0d57a3:
    .byte $E0 ; previous-row copy escape
    .byte $10 ; row-distance/count
    .byte $C4 ; same-value copy count/distance
