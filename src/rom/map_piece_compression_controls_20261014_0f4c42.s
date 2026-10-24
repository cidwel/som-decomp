.setcpu "65816"
.segment "CODE"
.org $4C42
map_control_0f4c42:
    .byte $E0 ; previous-row copy escape
    .byte $95 ; row-distance/count
    .byte $C2 ; same-value copy count/distance
