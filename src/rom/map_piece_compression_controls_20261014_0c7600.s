.setcpu "65816"
.segment "CODE"
.org $7600
map_control_0c7600:
    .byte $E0 ; previous-row copy escape
    .byte $17 ; row-distance/count
