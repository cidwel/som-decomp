.setcpu "65816"
.segment "CODE"
.org $39AB
map_control_0c39ab:
    .byte $E0 ; previous-row copy escape
    .byte $23 ; row-distance/count
