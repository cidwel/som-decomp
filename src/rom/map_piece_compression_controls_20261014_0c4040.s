.setcpu "65816"
.segment "CODE"
.org $4040
map_control_0c4040:
    .byte $E0 ; previous-row copy escape
    .byte $1A ; row-distance/count
