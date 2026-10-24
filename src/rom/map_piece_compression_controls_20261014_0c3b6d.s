.setcpu "65816"
.segment "CODE"
.org $3B6D
map_control_0c3b6d:
    .byte $E0 ; previous-row copy escape
    .byte $1F ; row-distance/count
