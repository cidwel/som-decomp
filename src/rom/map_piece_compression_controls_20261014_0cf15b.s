.setcpu "65816"
.segment "CODE"
.org $F15B
map_control_0cf15b:
    .byte $E0 ; previous-row copy escape
    .byte $0E ; row-distance/count
