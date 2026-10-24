.setcpu "65816"
.segment "CODE"
.org $4C8E
map_control_0c4c8e:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
