.setcpu "65816"
.segment "CODE"
.org $11BD
map_control_0c11bd:
    .byte $C5 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $4F ; row-distance/count
