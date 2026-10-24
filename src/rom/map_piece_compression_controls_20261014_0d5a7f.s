.setcpu "65816"
.segment "CODE"
.org $5A7F
map_control_0d5a7f:
    .byte $C4 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
