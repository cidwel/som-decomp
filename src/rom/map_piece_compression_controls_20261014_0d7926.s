.setcpu "65816"
.segment "CODE"
.org $7926
map_control_0d7926:
    .byte $C1 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $22 ; row-distance/count
