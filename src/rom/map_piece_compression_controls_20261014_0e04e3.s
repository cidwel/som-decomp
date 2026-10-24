.setcpu "65816"
.segment "CODE"
.org $04E3
map_control_0e04e3:
    .byte $E0 ; previous-row copy escape
    .byte $10 ; row-distance/count
