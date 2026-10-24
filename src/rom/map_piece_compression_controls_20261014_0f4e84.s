.setcpu "65816"
.segment "CODE"
.org $4E84
map_control_0f4e84:
    .byte $E0 ; previous-row copy escape
    .byte $82 ; row-distance/count
    .byte $C2 ; same-value copy count/distance
