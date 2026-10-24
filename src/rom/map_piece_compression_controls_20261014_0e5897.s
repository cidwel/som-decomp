.setcpu "65816"
.segment "CODE"
.org $5897
map_control_0e5897:
    .byte $E0 ; previous-row copy escape
    .byte $10 ; row-distance/count
    .byte $C1 ; same-value copy count/distance
