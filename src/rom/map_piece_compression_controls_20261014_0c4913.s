.setcpu "65816"
.segment "CODE"
.org $4913
map_control_0c4913:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
