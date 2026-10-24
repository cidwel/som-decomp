.setcpu "65816"
.segment "CODE"
.org $E855
map_control_0de855:
    .byte $C5 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
