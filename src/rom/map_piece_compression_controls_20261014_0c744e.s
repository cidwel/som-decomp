.setcpu "65816"
.segment "CODE"
.org $744E
map_control_0c744e:
    .byte $E0 ; previous-row copy escape
    .byte $84 ; row-distance/count
