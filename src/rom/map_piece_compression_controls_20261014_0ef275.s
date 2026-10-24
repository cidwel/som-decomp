.setcpu "65816"
.segment "CODE"
.org $F275
map_control_0ef275:
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
