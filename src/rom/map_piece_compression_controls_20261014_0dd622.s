.setcpu "65816"
.segment "CODE"
.org $D622
map_control_0dd622:
    .byte $E0 ; previous-row copy escape
    .byte $0E ; row-distance/count
