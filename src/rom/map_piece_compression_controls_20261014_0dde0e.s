.setcpu "65816"
.segment "CODE"
.org $DE0E
map_control_0dde0e:
    .byte $E0 ; previous-row copy escape
    .byte $0E ; row-distance/count
