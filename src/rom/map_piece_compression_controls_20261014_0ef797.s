.setcpu "65816"
.segment "CODE"
.org $F797
map_control_0ef797:
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
