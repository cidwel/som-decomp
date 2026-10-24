.setcpu "65816"
.segment "CODE"
.org $1477
map_control_0c1477:
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
