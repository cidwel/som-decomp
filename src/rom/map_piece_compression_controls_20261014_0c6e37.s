.setcpu "65816"
.segment "CODE"
.org $6E37
map_control_0c6e37:
    .byte $E0 ; previous-row copy escape
    .byte $83 ; row-distance/count
