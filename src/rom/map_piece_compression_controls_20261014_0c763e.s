.setcpu "65816"
.segment "CODE"
.org $763E
map_control_0c763e:
    .byte $E0 ; previous-row copy escape
    .byte $33 ; row-distance/count
