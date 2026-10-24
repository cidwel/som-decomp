.setcpu "65816"
.segment "CODE"
.org $43B0
map_control_0f43b0:
    .byte $C1 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $21 ; row-distance/count
