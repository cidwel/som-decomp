.setcpu "65816"
.segment "CODE"
.org $CA97
map_control_0fca97:
    .byte $E0 ; previous-row copy escape
    .byte $11 ; row-distance/count
