.setcpu "65816"
.segment "CODE"
.org $708E
map_control_0d708e:
    .byte $E0 ; previous-row copy escape
    .byte $84 ; row-distance/count
