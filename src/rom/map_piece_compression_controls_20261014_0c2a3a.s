.setcpu "65816"
.segment "CODE"
.org $2A3A
map_control_0c2a3a:
    .byte $E0 ; previous-row copy escape
    .byte $12 ; row-distance/count
