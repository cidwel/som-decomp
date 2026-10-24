.setcpu "65816"
.segment "CODE"
.org $E8C4
map_control_0de8c4:
    .byte $C1 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
