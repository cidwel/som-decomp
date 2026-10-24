.setcpu "65816"
.segment "CODE"
.org $B1DD
map_control_0eb1dd:
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
