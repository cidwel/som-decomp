.setcpu "65816"
.segment "CODE"
.org $2A9D
map_control_0c2a9d:
    .byte $E0 ; previous-row copy escape
    .byte $11 ; row-distance/count
