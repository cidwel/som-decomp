.setcpu "65816"
.segment "CODE"
.org $30B8
map_control_0d30b8:
    .byte $E0 ; previous-row copy escape
    .byte $83 ; row-distance/count
