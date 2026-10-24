.setcpu "65816"
.segment "CODE"
.org $84BF
map_control_0d84bf:
    .byte $C4 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
