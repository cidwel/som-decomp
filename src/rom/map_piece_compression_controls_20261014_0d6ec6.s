.setcpu "65816"
.segment "CODE"
.org $6EC6
map_control_0d6ec6:
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
