.setcpu "65816"
.segment "CODE"
.org $6272
map_control_0d6272:
    .byte $E0 ; previous-row copy escape
    .byte $14 ; row-distance/count
    .byte $C3 ; same-value copy count/distance
