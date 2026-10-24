.setcpu "65816"
.segment "CODE"
.org $E584
map_control_0fe584:
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
    .byte $C1 ; same-value copy count/distance
