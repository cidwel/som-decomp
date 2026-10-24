.setcpu "65816"
.segment "CODE"
.org $6508
map_control_0d6508:
    .byte $E0 ; previous-row copy escape
    .byte $1F ; row-distance/count
