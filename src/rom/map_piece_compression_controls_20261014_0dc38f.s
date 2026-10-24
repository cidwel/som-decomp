.setcpu "65816"
.segment "CODE"
.org $C38F
map_control_0dc38f:
    .byte $E0 ; previous-row copy escape
    .byte $1F ; row-distance/count
