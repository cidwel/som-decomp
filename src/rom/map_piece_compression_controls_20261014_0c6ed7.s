.setcpu "65816"
.segment "CODE"
.org $6ED7
map_control_0c6ed7:
    .byte $E0 ; previous-row copy escape
    .byte $85 ; row-distance/count
