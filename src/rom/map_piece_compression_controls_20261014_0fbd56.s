.setcpu "65816"
.segment "CODE"
.org $BD56
map_control_0fbd56:
    .byte $C3 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $46 ; row-distance/count
