.setcpu "65816"
.segment "CODE"
.org $8D37
map_control_0c8d37:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
