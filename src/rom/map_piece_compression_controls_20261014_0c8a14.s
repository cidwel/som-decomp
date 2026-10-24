.setcpu "65816"
.segment "CODE"
.org $8A14
map_control_0c8a14:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
