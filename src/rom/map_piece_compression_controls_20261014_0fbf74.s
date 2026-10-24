.setcpu "65816"
.segment "CODE"
.org $BF74
map_control_0fbf74:
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
