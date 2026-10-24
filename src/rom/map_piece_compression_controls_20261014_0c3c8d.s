.setcpu "65816"
.segment "CODE"
.org $3C8D
map_control_0c3c8d:
    .byte $E0 ; previous-row copy escape
    .byte $17 ; row-distance/count
