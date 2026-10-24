.setcpu "65816"
.segment "CODE"
.org $F074
map_control_0cf074:
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
