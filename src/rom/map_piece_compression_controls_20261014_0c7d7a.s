.setcpu "65816"
.segment "CODE"
.org $7D7A
map_control_0c7d7a:
    .byte $E0 ; previous-row copy escape
    .byte $27 ; row-distance/count
