.setcpu "65816"
.segment "CODE"
.org $82D9
map_control_0d82d9:
    .byte $C4 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
