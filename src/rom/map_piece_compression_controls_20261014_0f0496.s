.setcpu "65816"
.segment "CODE"
.org $0496
map_control_0f0496:
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
