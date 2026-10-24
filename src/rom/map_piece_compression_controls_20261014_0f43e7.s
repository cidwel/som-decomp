.setcpu "65816"
.segment "CODE"
.org $43E7
map_control_0f43e7:
    .byte $C1 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $27 ; row-distance/count
