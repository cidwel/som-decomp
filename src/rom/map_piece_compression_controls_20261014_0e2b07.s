.setcpu "65816"
.segment "CODE"
.org $2B07
map_control_0e2b07:
    .byte $C6 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $20 ; row-distance/count
