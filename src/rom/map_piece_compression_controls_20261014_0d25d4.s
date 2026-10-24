.setcpu "65816"
.segment "CODE"
.org $25D4
map_control_0d25d4:
    .byte $C4 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $85 ; row-distance/count
