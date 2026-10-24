.setcpu "65816"
.segment "CODE"
.org $8E00
map_control_0d8e00:
    .byte $C1 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $87 ; row-distance/count
