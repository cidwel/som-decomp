.setcpu "65816"
.segment "CODE"
.org $04B2
map_control_0e04b2:
    .byte $E0 ; previous-row copy escape
    .byte $13 ; row-distance/count
