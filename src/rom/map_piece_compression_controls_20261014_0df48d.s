.setcpu "65816"
.segment "CODE"
.org $F48D
map_control_0df48d:
    .byte $E0 ; previous-row copy escape
    .byte $18 ; row-distance/count
