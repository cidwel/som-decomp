.setcpu "65816"
.segment "CODE"
.org $17BF
map_control_0e17bf:
    .byte $E0 ; previous-row copy escape
    .byte $1A ; row-distance/count
