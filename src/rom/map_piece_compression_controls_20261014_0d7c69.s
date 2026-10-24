.setcpu "65816"
.segment "CODE"
.org $7C69
map_control_0d7c69:
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
