.setcpu "65816"
.segment "CODE"
.org $928F
map_control_0d928f:
    .byte $C7 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $BB ; row-distance/count
