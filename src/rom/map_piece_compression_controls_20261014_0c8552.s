.setcpu "65816"
.segment "CODE"
.org $8552
map_control_0c8552:
    .byte $E0 ; previous-row copy escape
    .byte $3E ; row-distance/count
