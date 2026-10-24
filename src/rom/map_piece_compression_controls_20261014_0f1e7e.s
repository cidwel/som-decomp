.setcpu "65816"
.segment "CODE"
.org $1E7E
map_control_0f1e7e:
    .byte $E0 ; previous-row copy escape
    .byte $19 ; row-distance/count
