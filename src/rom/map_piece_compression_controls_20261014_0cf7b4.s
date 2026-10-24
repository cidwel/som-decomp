.setcpu "65816"
.segment "CODE"
.org $F7B4
map_control_0cf7b4:
    .byte $E0 ; previous-row copy escape
    .byte $15 ; row-distance/count
