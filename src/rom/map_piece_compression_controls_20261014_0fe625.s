.setcpu "65816"
.segment "CODE"
.org $E625
map_control_0fe625:
    .byte $E0 ; previous-row copy escape
    .byte $1A ; row-distance/count
