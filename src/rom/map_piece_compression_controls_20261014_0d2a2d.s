.setcpu "65816"
.segment "CODE"
.org $2A2D
map_control_0d2a2d:
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
    .byte $C1 ; same-value copy count/distance
