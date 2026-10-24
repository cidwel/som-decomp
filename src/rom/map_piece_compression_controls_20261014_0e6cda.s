.setcpu "65816"
.segment "CODE"
.org $6CDA
map_control_0e6cda:
    .byte $E0 ; previous-row copy escape
    .byte $10 ; row-distance/count
