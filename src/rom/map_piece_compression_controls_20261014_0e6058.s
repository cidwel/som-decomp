.setcpu "65816"
.segment "CODE"
.org $6058
map_control_0e6058:
    .byte $E0 ; previous-row copy escape
    .byte $29 ; row-distance/count
