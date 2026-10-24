.setcpu "65816"
.segment "CODE"
.org $8610
map_control_0e8610:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
