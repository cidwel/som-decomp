.setcpu "65816"
.segment "CODE"
.org $4853
map_control_0f4853:
    .byte $C3 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
