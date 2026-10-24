.setcpu "65816"
.segment "CODE"
.org $4793
map_control_0f4793:
    .byte $E0 ; previous-row copy escape
    .byte $55 ; row-distance/count
