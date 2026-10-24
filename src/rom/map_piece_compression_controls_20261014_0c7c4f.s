.setcpu "65816"
.segment "CODE"
.org $7C4F
map_control_0c7c4f:
    .byte $C6 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $3A ; row-distance/count
