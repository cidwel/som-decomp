.setcpu "65816"
.segment "CODE"
.org $125E
map_control_0e125e:
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
