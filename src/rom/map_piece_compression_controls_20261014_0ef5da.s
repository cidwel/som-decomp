.setcpu "65816"
.segment "CODE"
.org $F5DA
map_control_0ef5da:
    .byte $E0 ; previous-row copy escape
    .byte $15 ; row-distance/count
