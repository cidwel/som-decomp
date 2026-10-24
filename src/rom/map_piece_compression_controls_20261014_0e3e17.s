.setcpu "65816"
.segment "CODE"
.org $3E17
map_control_0e3e17:
    .byte $E0 ; previous-row copy escape
    .byte $15 ; row-distance/count
