.setcpu "65816"
.segment "CODE"
.org $25FE
map_control_0d25fe:
    .byte $C2 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $15 ; row-distance/count
