.setcpu "65816"
.segment "CODE"
.org $D496
map_control_0fd496:
    .byte $E0 ; previous-row copy escape
    .byte $2C ; row-distance/count
