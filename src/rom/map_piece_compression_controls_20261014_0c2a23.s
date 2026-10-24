.setcpu "65816"
.segment "CODE"
.org $2A23
map_control_0c2a23:
    .byte $E0 ; previous-row copy escape
    .byte $14 ; row-distance/count
