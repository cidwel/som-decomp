.setcpu "65816"
.segment "CODE"
.org $8C19
map_control_0f8c19:
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
