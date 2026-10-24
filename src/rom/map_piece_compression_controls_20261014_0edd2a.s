.setcpu "65816"
.segment "CODE"
.org $DD2A
map_control_0edd2a:
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
