.setcpu "65816"
.segment "CODE"
.org $1B1E
map_control_0f1b1e:
    .byte $E0 ; previous-row copy escape
    .byte $42 ; row-distance/count
