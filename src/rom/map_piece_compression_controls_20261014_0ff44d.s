.setcpu "65816"
.segment "CODE"
.org $F44D
map_control_0ff44d:
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
