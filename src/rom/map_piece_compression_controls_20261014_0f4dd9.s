.setcpu "65816"
.segment "CODE"
.org $4DD9
map_control_0f4dd9:
    .byte $E0 ; previous-row copy escape
    .byte $12 ; row-distance/count
