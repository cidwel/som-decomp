.setcpu "65816"
.segment "CODE"
.org $033D
map_control_0f033d:
    .byte $E0 ; previous-row copy escape
    .byte $1A ; row-distance/count
