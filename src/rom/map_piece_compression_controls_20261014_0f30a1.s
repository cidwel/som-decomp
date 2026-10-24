.setcpu "65816"
.segment "CODE"
.org $30A1
map_control_0f30a1:
    .byte $E0 ; previous-row copy escape
    .byte $13 ; row-distance/count
