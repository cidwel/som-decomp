.setcpu "65816"
.segment "CODE"
.org $F9E9
map_control_0ff9e9:
    .byte $E0 ; previous-row copy escape
    .byte $48 ; row-distance/count
