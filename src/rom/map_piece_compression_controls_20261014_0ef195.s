.setcpu "65816"
.segment "CODE"
.org $F195
map_control_0ef195:
    .byte $E0 ; previous-row copy escape
    .byte $15 ; row-distance/count
