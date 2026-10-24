.setcpu "65816"
.segment "CODE"
.org $5B8D
map_control_0e5b8d:
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
