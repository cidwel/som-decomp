.setcpu "65816"
.segment "CODE"
.org $11E6
map_control_0e11e6:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
