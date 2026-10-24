.setcpu "65816"
.segment "CODE"
.org $4B7E
map_control_0e4b7e:
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
