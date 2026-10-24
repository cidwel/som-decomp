.setcpu "65816"
.segment "CODE"
.org $416A
map_control_0c416a:
    .byte $E0 ; previous-row copy escape
    .byte $1D ; row-distance/count
