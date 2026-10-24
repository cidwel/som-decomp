.setcpu "65816"
.segment "CODE"
.org $85D2
map_control_0c85d2:
    .byte $E0 ; previous-row copy escape
    .byte $40 ; row-distance/count
    .byte $C1 ; same-value copy count/distance
