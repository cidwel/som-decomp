.setcpu "65816"
.segment "CODE"
.org $84D0
map_control_0c84d0:
    .byte $E0 ; previous-row copy escape
    .byte $34 ; row-distance/count
