.setcpu "65816"
.segment "CODE"
.org $FA45
map_control_0efa45:
    .byte $E0 ; previous-row copy escape
    .byte $97 ; row-distance/count
