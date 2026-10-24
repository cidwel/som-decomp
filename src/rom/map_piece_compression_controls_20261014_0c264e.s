.setcpu "65816"
.segment "CODE"
.org $264E
map_control_0c264e:
    .byte $E0 ; previous-row copy escape
    .byte $18 ; row-distance/count
