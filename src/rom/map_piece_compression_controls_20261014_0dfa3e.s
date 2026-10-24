.setcpu "65816"
.segment "CODE"
.org $FA3E
map_control_0dfa3e:
    .byte $E0 ; previous-row copy escape
    .byte $0E ; row-distance/count
