.setcpu "65816"
.segment "CODE"
.org $5B24
map_control_0d5b24:
    .byte $E0 ; previous-row copy escape
    .byte $17 ; row-distance/count
