.setcpu "65816"
.segment "CODE"
.org $8A1B
map_control_0e8a1b:
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
