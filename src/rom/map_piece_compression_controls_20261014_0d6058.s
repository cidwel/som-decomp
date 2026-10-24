.setcpu "65816"
.segment "CODE"
.org $6058
map_control_0d6058:
    .byte $E0 ; previous-row copy escape
    .byte $21 ; row-distance/count
