.setcpu "65816"
.segment "CODE"
.org $AC7F
map_control_0eac7f:
    .byte $E0 ; previous-row copy escape
    .byte $18 ; row-distance/count
