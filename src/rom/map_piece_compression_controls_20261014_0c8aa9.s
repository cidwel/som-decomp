.setcpu "65816"
.segment "CODE"
.org $8AA9
map_control_0c8aa9:
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
    .byte $C1 ; same-value copy count/distance
