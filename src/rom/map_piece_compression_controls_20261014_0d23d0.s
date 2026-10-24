.setcpu "65816"
.segment "CODE"
.org $23D0
map_control_0d23d0:
    .byte $E0 ; previous-row copy escape
    .byte $16 ; row-distance/count
