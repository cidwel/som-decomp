.setcpu "65816"
.segment "CODE"
.org $1D92
map_control_0d1d92:
    .byte $E0 ; previous-row copy escape
    .byte $13 ; row-distance/count
