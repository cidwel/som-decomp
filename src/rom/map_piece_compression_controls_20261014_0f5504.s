.setcpu "65816"
.segment "CODE"
.org $5504
map_control_0f5504:
    .byte $E0 ; previous-row copy escape
    .byte $15 ; row-distance/count
    .byte $C4 ; same-value copy count/distance
