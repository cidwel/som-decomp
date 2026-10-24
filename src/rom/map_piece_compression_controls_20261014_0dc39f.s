.setcpu "65816"
.segment "CODE"
.org $C39F
map_control_0dc39f:
    .byte $E0 ; previous-row copy escape
    .byte $1F ; row-distance/count
