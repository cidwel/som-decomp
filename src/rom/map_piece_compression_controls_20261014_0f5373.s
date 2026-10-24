.setcpu "65816"
.segment "CODE"
.org $5373
map_control_0f5373:
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
