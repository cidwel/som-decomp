.setcpu "65816"
.segment "CODE"
.org $6B7E
map_control_0c6b7e:
    .byte $E0 ; previous-row copy escape
    .byte $14 ; row-distance/count
