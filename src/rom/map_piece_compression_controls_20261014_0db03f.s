.setcpu "65816"
.segment "CODE"
.org $B03F
map_control_0db03f:
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
    .byte $C1 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $82 ; row-distance/count
    .byte $C1 ; same-value copy count/distance
