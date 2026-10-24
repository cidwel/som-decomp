.setcpu "65816"
.segment "CODE"
.org $F305
map_control_0df305:
    .byte $E0 ; previous-row copy escape
    .byte $89 ; row-distance/count
