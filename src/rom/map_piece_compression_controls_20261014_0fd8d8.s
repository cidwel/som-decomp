.setcpu "65816"
.segment "CODE"
.org $D8D8
map_control_0fd8d8:
    .byte $E0 ; previous-row copy escape
    .byte $17 ; row-distance/count
    .byte $C7 ; same-value copy count/distance
