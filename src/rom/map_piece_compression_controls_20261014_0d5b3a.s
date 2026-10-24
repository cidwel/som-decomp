.setcpu "65816"
.segment "CODE"
.org $5B3A
map_control_0d5b3a:
    .byte $E0 ; previous-row copy escape
    .byte $17 ; row-distance/count
