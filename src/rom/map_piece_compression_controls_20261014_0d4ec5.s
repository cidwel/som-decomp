.setcpu "65816"
.segment "CODE"
.org $4EC5
map_control_0d4ec5:
    .byte $E0 ; previous-row copy escape
    .byte $1A ; row-distance/count
