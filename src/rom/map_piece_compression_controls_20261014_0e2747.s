.setcpu "65816"
.segment "CODE"
.org $2747
map_control_0e2747:
    .byte $C3 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $39 ; row-distance/count
