.setcpu "65816"
.segment "CODE"
.org $9448
map_control_0e9448:
    .byte $E0 ; previous-row copy escape
    .byte $9B ; row-distance/count
    .byte $C4 ; same-value copy count/distance
