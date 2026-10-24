.setcpu "65816"
.segment "CODE"
.org $6F45
map_control_0c6f45:
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
