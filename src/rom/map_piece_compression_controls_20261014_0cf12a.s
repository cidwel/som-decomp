.setcpu "65816"
.segment "CODE"
.org $F12A
map_control_0cf12a:
    .byte $E0 ; previous-row copy escape
    .byte $83 ; row-distance/count
