.setcpu "65816"
.segment "CODE"
.org $3B78
map_control_0c3b78:
    .byte $E0 ; previous-row copy escape
    .byte $15 ; row-distance/count
