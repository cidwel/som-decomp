.setcpu "65816"
.segment "CODE"
.org $8FE3
map_control_0f8fe3:
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
