.setcpu "65816"
.segment "CODE"
.org $BE48
map_control_0dbe48:
    .byte $E0 ; previous-row copy escape
    .byte $27 ; row-distance/count
