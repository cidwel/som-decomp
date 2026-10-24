.setcpu "65816"
.segment "CODE"
.org $1EF6
map_control_0c1ef6:
    .byte $E0 ; previous-row copy escape
    .byte $15 ; row-distance/count
