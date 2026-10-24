.setcpu "65816"
.segment "CODE"
.org $C990
map_control_0dc990:
    .byte $C2 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $11 ; row-distance/count
