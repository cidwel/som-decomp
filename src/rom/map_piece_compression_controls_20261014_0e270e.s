.setcpu "65816"
.segment "CODE"
.org $270E
map_control_0e270e:
    .byte $E0 ; previous-row copy escape
    .byte $13 ; row-distance/count
