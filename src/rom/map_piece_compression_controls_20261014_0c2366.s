.setcpu "65816"
.segment "CODE"
.org $2366
map_control_0c2366:
    .byte $E0 ; previous-row copy escape
    .byte $1A ; row-distance/count
