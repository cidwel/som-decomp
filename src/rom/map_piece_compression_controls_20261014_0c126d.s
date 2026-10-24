.setcpu "65816"
.segment "CODE"
.org $126D
map_control_0c126d:
    .byte $E0 ; previous-row copy escape
    .byte $23 ; row-distance/count
