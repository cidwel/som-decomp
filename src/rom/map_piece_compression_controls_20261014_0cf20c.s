.setcpu "65816"
.segment "CODE"
.org $F20C
map_control_0cf20c:
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
