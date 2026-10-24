.setcpu "65816"
.segment "CODE"
.org $DEC5
map_control_0edec5:
    .byte $E0 ; previous-row copy escape
    .byte $18 ; row-distance/count
