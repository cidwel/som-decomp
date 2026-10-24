.setcpu "65816"
.segment "CODE"
.org $4760
map_control_0f4760:
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
    .byte $C1 ; same-value copy count/distance
