.setcpu "65816"
.segment "CODE"
.org $8D9F
map_control_0d8d9f:
    .byte $E0 ; previous-row copy escape
    .byte $82 ; row-distance/count
    .byte $C4 ; same-value copy count/distance
