.setcpu "65816"
.segment "CODE"
.org $D0A8
map_control_0dd0a8:
    .byte $E0 ; previous-row copy escape
    .byte $1A ; row-distance/count
