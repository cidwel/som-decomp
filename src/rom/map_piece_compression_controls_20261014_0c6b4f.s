.setcpu "65816"
.segment "CODE"
.org $6B4F
map_control_0c6b4f:
    .byte $E0 ; previous-row copy escape
    .byte $96 ; row-distance/count
    .byte $C4 ; same-value copy count/distance
