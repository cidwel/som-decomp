.setcpu "65816"
.segment "CODE"
.org $AF0F
map_control_0faf0f:
    .byte $C1 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $20 ; row-distance/count
