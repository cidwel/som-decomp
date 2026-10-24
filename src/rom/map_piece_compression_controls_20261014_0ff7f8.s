.setcpu "65816"
.segment "CODE"
.org $F7F8
map_control_0ff7f8:
    .byte $E0 ; previous-row copy escape
    .byte $10 ; row-distance/count
