.setcpu "65816"
.segment "CODE"
.org $355E
map_control_0c355e:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
