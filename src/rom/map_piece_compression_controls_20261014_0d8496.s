.setcpu "65816"
.segment "CODE"
.org $8496
map_control_0d8496:
    .byte $E0 ; previous-row copy escape
    .byte $12 ; row-distance/count
