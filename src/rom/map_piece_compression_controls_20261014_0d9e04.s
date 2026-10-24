.setcpu "65816"
.segment "CODE"
.org $9E04
map_control_0d9e04:
    .byte $E0 ; previous-row copy escape
    .byte $3F ; row-distance/count
