.setcpu "65816"
.segment "CODE"
.org $CA8F
map_control_0dca8f:
    .byte $E0 ; previous-row copy escape
    .byte $83 ; row-distance/count
    .byte $C3 ; same-value copy count/distance
