.setcpu "65816"
.segment "CODE"
.org $271A
map_control_0e271a:
    .byte $E0 ; previous-row copy escape
    .byte $1A ; row-distance/count
