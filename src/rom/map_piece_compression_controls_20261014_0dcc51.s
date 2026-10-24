.setcpu "65816"
.segment "CODE"
.org $CC51
map_control_0dcc51:
    .byte $E0 ; previous-row copy escape
    .byte $1B ; row-distance/count
