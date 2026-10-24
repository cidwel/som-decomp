.setcpu "65816"
.segment "CODE"
.org $7CAA
map_control_0c7caa:
    .byte $E0 ; previous-row copy escape
    .byte $8A ; row-distance/count
