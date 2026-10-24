.setcpu "65816"
.segment "CODE"
.org $F3E3
map_control_0df3e3:
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
