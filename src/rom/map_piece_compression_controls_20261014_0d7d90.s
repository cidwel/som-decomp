.setcpu "65816"
.segment "CODE"
.org $7D90
map_control_0d7d90:
    .byte $E3 ; previous-row copy count
    .byte $C1 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
