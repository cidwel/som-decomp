.setcpu "65816"
.segment "CODE"
.org $1091
map_control_0d1091:
    .byte $E0 ; previous-row copy escape
    .byte $82 ; row-distance/count
