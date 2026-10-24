.setcpu "65816"
.segment "CODE"
.org $2DF7
map_control_0c2df7:
    .byte $E0 ; previous-row copy escape
    .byte $1F ; row-distance/count
