.setcpu "65816"
.segment "CODE"
.org $F760
map_control_0ff760:
    .byte $E0 ; previous-row copy escape
    .byte $10 ; row-distance/count
