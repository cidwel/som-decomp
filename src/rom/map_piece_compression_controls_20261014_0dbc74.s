.setcpu "65816"
.segment "CODE"
.org $BC74
map_control_0dbc74:
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
