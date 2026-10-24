.setcpu "65816"
.segment "CODE"
.org $8583
map_control_0f8583:
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
    .byte $C1 ; same-value copy count/distance
