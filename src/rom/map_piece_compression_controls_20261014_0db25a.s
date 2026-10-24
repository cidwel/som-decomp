.setcpu "65816"
.segment "CODE"
.org $B25A
map_control_0db25a:
    .byte $E0 ; previous-row copy escape
    .byte $18 ; row-distance/count
    .byte $C6 ; same-value copy count/distance
