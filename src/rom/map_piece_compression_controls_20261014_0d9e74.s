.setcpu "65816"
.segment "CODE"
.org $9E74
map_control_0d9e74:
    .byte $E0 ; previous-row copy escape
    .byte $3F ; row-distance/count
