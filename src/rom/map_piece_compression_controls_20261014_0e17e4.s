.setcpu "65816"
.segment "CODE"
.org $17E4
map_control_0e17e4:
    .byte $E0 ; previous-row copy escape
    .byte $10 ; row-distance/count
