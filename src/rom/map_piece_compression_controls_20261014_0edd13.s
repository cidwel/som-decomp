.setcpu "65816"
.segment "CODE"
.org $DD13
map_control_0edd13:
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
