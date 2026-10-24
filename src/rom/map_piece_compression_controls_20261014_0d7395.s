.setcpu "65816"
.segment "CODE"
.org $7395
map_control_0d7395:
    .byte $E0 ; previous-row copy escape
    .byte $B4 ; row-distance/count
    .byte $C1 ; same-value copy count/distance
