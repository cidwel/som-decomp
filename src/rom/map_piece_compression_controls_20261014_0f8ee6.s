.setcpu "65816"
.segment "CODE"
.org $8EE6
map_control_0f8ee6:
    .byte $E0 ; previous-row copy escape
    .byte $26 ; row-distance/count
