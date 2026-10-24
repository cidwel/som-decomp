.setcpu "65816"
.segment "CODE"
.org $ED74
map_control_0ded74:
    .byte $E0 ; previous-row copy escape
    .byte $16 ; row-distance/count
