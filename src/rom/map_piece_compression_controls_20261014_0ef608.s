.setcpu "65816"
.segment "CODE"
.org $F608
map_control_0ef608:
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
