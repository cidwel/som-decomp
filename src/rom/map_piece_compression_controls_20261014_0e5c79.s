.setcpu "65816"
.segment "CODE"
.org $5C79
map_control_0e5c79:
    .byte $E0 ; previous-row copy escape
    .byte $1A ; row-distance/count
