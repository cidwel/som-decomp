.setcpu "65816"
.segment "CODE"
.org $C68F
map_control_0dc68f:
    .byte $E0 ; previous-row copy escape
    .byte $9A ; row-distance/count
