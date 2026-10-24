.setcpu "65816"
.segment "CODE"
.org $5B72
map_control_0e5b72:
    .byte $E0 ; previous-row copy escape
    .byte $82 ; row-distance/count
