.setcpu "65816"
.segment "CODE"
.org $12E5
map_control_0d12e5:
    .byte $E0 ; previous-row copy escape
    .byte $1A ; row-distance/count
