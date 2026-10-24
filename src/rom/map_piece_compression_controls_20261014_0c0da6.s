.setcpu "65816"
.segment "CODE"
.org $0DA6
map_control_0c0da6:
    .byte $E0 ; previous-row copy escape
    .byte $8B ; row-distance/count
