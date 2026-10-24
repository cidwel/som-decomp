.setcpu "65816"
.segment "CODE"
.org $EA7E
map_control_0eea7e:
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
