.setcpu "65816"
.segment "CODE"
.org $2A8A
map_control_0c2a8a:
    .byte $E0 ; previous-row copy escape
    .byte $11 ; row-distance/count
