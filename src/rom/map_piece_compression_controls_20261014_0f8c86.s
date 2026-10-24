.setcpu "65816"
.segment "CODE"
.org $8C86
map_control_0f8c86:
    .byte $E0 ; previous-row copy escape
    .byte $1A ; row-distance/count
