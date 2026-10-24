.setcpu "65816"
.segment "CODE"
.org $757E
map_control_0e757e:
    .byte $E0 ; previous-row copy escape
    .byte $15 ; row-distance/count
