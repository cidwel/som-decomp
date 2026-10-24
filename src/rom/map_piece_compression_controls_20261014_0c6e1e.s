.setcpu "65816"
.segment "CODE"
.org $6E1E
map_control_0c6e1e:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
