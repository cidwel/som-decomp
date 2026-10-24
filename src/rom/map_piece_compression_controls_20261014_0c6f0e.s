.setcpu "65816"
.segment "CODE"
.org $6F0E
map_control_0c6f0e:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
