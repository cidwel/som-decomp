.setcpu "65816"
.segment "CODE"
.org $F441
map_control_0ff441:
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
