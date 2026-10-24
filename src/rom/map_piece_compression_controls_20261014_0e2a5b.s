.setcpu "65816"
.segment "CODE"
.org $2A5B
map_control_0e2a5b:
    .byte $E0 ; previous-row copy escape
    .byte $14 ; row-distance/count
