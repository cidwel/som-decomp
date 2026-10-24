.setcpu "65816"
.segment "CODE"
.org $DF98
map_control_0ddf98:
    .byte $E0 ; previous-row copy escape
    .byte $10 ; row-distance/count
