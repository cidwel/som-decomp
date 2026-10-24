.setcpu "65816"
.segment "CODE"
.org $FE78
map_control_0dfe78:
    .byte $E0 ; previous-row copy escape
    .byte $10 ; row-distance/count
