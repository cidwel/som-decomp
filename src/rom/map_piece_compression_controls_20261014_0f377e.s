.setcpu "65816"
.segment "CODE"
.org $377E
map_control_0f377e:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
