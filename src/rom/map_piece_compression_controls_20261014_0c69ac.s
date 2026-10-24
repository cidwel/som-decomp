.setcpu "65816"
.segment "CODE"
.org $69AC
map_control_0c69ac:
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
