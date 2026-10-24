.setcpu "65816"
.segment "CODE"
.org $CC1F
map_control_0dcc1f:
    .byte $E0 ; previous-row copy escape
    .byte $1D ; row-distance/count
