.setcpu "65816"
.segment "CODE"
.org $AC2F
map_control_0eac2f:
    .byte $E0 ; previous-row copy escape
    .byte $14 ; row-distance/count
