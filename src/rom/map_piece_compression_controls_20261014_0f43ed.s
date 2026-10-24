.setcpu "65816"
.segment "CODE"
.org $43ED
map_control_0f43ed:
    .byte $C2 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $16 ; row-distance/count
