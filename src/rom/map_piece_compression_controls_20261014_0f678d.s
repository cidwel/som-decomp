.setcpu "65816"
.segment "CODE"
.org $678D
map_control_0f678d:
    .byte $E0 ; previous-row copy escape
    .byte $15 ; row-distance/count
