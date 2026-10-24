.setcpu "65816"
.segment "CODE"
.org $60D7
map_control_0f60d7:
    .byte $E0 ; previous-row copy escape
    .byte $15 ; row-distance/count
