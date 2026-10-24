.setcpu "65816"
.segment "CODE"
.org $1192
map_control_0c1192:
    .byte $E0 ; previous-row copy escape
    .byte $95 ; row-distance/count
