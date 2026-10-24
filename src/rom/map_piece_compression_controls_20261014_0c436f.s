.setcpu "65816"
.segment "CODE"
.org $436F
map_control_0c436f:
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
