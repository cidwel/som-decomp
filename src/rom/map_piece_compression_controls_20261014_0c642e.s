.setcpu "65816"
.segment "CODE"
.org $642E
map_control_0c642e:
    .byte $E0 ; previous-row copy escape
    .byte $84 ; row-distance/count
