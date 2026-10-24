.setcpu "65816"
.segment "CODE"
.org $2CC6
map_control_0d2cc6:
    .byte $D1 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
