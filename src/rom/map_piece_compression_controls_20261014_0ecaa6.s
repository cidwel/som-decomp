.setcpu "65816"
.segment "CODE"
.org $CAA6
map_control_0ecaa6:
    .byte $E0 ; previous-row copy escape
    .byte $0E ; row-distance/count
