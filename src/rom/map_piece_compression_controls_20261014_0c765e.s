.setcpu "65816"
.segment "CODE"
.org $765E
map_control_0c765e:
    .byte $E0 ; previous-row copy escape
    .byte $33 ; row-distance/count
