.setcpu "65816"
.segment "CODE"
.org $6BEA
map_control_0c6bea:
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
