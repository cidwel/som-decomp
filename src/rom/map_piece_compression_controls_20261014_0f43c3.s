.setcpu "65816"
.segment "CODE"
.org $43C3
map_control_0f43c3:
    .byte $C1 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
