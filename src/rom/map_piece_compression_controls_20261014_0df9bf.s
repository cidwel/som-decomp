.setcpu "65816"
.segment "CODE"
.org $F9BF
map_control_0df9bf:
    .byte $E0 ; previous-row copy escape
    .byte $1F ; row-distance/count
