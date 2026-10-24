.setcpu "65816"
.segment "CODE"
.org $4E74
map_control_0d4e74:
    .byte $E0 ; previous-row copy escape
    .byte $16 ; row-distance/count
