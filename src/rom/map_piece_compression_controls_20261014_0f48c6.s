.setcpu "65816"
.segment "CODE"
.org $48C6
map_control_0f48c6:
    .byte $E0 ; previous-row copy escape
    .byte $11 ; row-distance/count
