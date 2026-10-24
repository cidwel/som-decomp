.setcpu "65816"
.segment "CODE"
.org $4B43
map_control_0e4b43:
    .byte $C4 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $90 ; row-distance/count
