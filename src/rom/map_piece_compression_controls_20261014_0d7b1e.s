.setcpu "65816"
.segment "CODE"
.org $7B1E
map_control_0d7b1e:
    .byte $E0 ; previous-row copy escape
    .byte $26 ; row-distance/count
