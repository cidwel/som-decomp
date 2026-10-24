.setcpu "65816"
.segment "CODE"
.org $FA71
map_control_0dfa71:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
