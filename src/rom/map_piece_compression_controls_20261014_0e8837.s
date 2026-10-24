.setcpu "65816"
.segment "CODE"
.org $8837
map_control_0e8837:
    .byte $E0 ; previous-row copy escape
    .byte $83 ; row-distance/count
