.setcpu "65816"
.segment "CODE"
.org $F45D
map_control_0cf45d:
    .byte $E0 ; previous-row copy escape
    .byte $97 ; row-distance/count
