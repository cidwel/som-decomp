.setcpu "65816"
.segment "CODE"
.org $2A21
map_control_0e2a21:
    .byte $E0 ; previous-row copy escape
    .byte $13 ; row-distance/count
