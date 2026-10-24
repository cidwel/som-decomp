.setcpu "65816"
.segment "CODE"
.org $F283
map_control_0ef283:
    .byte $E0 ; previous-row copy escape
    .byte $0E ; row-distance/count
