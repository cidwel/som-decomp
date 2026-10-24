.setcpu "65816"
.segment "CODE"
.org $8001
map_control_0d8001:
    .byte $E0 ; previous-row copy escape
    .byte $1A ; row-distance/count
