.setcpu "65816"
.segment "CODE"
.org $5418
map_control_0f5418:
    .byte $C5 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $21 ; row-distance/count
