.setcpu "65816"
.segment "CODE"
.org $F7F4
map_control_0cf7f4:
    .byte $E0 ; previous-row copy escape
    .byte $11 ; row-distance/count
