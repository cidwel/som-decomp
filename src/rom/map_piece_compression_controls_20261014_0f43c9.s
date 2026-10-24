.setcpu "65816"
.segment "CODE"
.org $43C9
map_control_0f43c9:
    .byte $E0 ; previous-row copy escape
    .byte $29 ; row-distance/count
    .byte $C1 ; same-value copy count/distance
