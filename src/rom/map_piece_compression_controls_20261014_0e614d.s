.setcpu "65816"
.segment "CODE"
.org $614D
map_control_0e614d:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
