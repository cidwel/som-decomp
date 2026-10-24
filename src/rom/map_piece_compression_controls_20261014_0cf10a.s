.setcpu "65816"
.segment "CODE"
.org $F10A
map_control_0cf10a:
    .byte $E0 ; previous-row copy escape
    .byte $8D ; row-distance/count
