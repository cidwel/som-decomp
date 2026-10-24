.setcpu "65816"
.segment "CODE"
.org $E7BF
map_control_0de7bf:
    .byte $E3 ; previous-row copy count
    .byte $C4 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
