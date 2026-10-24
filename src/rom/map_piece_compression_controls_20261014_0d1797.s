.setcpu "65816"
.segment "CODE"
.org $1797
map_control_0d1797:
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
