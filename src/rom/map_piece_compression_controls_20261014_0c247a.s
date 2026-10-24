.setcpu "65816"
.segment "CODE"
.org $247A
map_control_0c247a:
    .byte $E0 ; previous-row copy escape
    .byte $20 ; row-distance/count
    .byte $C2 ; same-value copy count/distance
