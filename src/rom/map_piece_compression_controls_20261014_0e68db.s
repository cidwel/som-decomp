.setcpu "65816"
.segment "CODE"
.org $68DB
map_control_0e68db:
    .byte $E0 ; previous-row copy escape
    .byte $2A ; row-distance/count
