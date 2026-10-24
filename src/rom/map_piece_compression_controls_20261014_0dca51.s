.setcpu "65816"
.segment "CODE"
.org $CA51
map_control_0dca51:
    .byte $E0 ; previous-row copy escape
    .byte $1A ; row-distance/count
