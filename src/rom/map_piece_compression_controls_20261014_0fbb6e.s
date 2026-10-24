.setcpu "65816"
.segment "CODE"
.org $BB6E
map_control_0fbb6e:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
