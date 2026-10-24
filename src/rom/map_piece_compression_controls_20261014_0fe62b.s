.setcpu "65816"
.segment "CODE"
.org $E62B
map_control_0fe62b:
    .byte $E0 ; previous-row copy escape
    .byte $1A ; row-distance/count
