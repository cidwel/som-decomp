.setcpu "65816"
.segment "CODE"
.org $8A73
map_control_0d8a73:
    .byte $E0 ; previous-row copy escape
    .byte $8D ; row-distance/count
