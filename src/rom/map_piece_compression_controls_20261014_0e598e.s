.setcpu "65816"
.segment "CODE"
.org $598E
map_control_0e598e:
    .byte $E0 ; previous-row copy escape
    .byte $10 ; row-distance/count
