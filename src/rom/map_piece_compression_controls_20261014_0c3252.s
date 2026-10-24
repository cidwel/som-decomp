.setcpu "65816"
.segment "CODE"
.org $3252
map_control_0c3252:
    .byte $E0 ; previous-row copy escape
    .byte $18 ; row-distance/count
    .byte $C1 ; same-value copy count/distance
