.setcpu "65816"
.segment "CODE"
.org $F21E
map_control_0cf21e:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
