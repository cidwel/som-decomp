.setcpu "65816"
.segment "CODE"
.org $6297
map_control_0d6297:
    .byte $E0 ; previous-row copy escape
    .byte $15 ; row-distance/count
    .byte $C1 ; same-value copy count/distance
