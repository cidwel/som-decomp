.setcpu "65816"
.segment "CODE"
.org $B31E
map_control_0db31e:
    .byte $E0 ; previous-row copy escape
    .byte $84 ; row-distance/count
