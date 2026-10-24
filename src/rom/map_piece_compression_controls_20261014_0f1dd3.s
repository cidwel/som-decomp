.setcpu "65816"
.segment "CODE"
.org $1DD3
map_control_0f1dd3:
    .byte $E0 ; previous-row copy escape
    .byte $1A ; row-distance/count
