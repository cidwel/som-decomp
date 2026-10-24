.setcpu "65816"
.segment "CODE"
.org $5AF0
map_control_0d5af0:
    .byte $E0 ; previous-row copy escape
    .byte $13 ; row-distance/count
    .byte $C1 ; same-value copy count/distance
