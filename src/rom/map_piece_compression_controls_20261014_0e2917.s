.setcpu "65816"
.segment "CODE"
.org $2917
map_control_0e2917:
    .byte $E0 ; previous-row copy escape
    .byte $13 ; row-distance/count
