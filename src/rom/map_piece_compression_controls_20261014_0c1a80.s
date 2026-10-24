.setcpu "65816"
.segment "CODE"
.org $1A80
map_control_0c1a80:
    .byte $E0 ; previous-row copy escape
    .byte $16 ; row-distance/count
