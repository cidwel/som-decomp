.setcpu "65816"
.segment "CODE"
.org $108A
map_control_0e108a:
    .byte $E0 ; previous-row copy escape
    .byte $1A ; row-distance/count
