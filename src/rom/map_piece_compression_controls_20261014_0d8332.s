.setcpu "65816"
.segment "CODE"
.org $8332
map_control_0d8332:
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
