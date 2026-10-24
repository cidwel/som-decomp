.setcpu "65816"
.segment "CODE"
.org $5A4C
map_control_0d5a4c:
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
