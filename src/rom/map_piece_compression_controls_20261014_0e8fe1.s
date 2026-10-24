.setcpu "65816"
.segment "CODE"
.org $8FE1
map_control_0e8fe1:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
