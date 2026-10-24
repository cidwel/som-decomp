.setcpu "65816"
.segment "CODE"
.org $7A8E
map_control_0f7a8e:
    .byte $E1 ; previous-row copy count
    .byte $C4 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
