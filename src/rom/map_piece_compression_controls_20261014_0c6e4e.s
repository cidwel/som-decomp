.setcpu "65816"
.segment "CODE"
.org $6E4E
map_control_0c6e4e:
    .byte $E0 ; previous-row copy escape
    .byte $17 ; row-distance/count
