.setcpu "65816"
.segment "CODE"
.org $0DD3
map_control_0c0dd3:
    .byte $E0 ; previous-row copy escape
    .byte $11 ; row-distance/count
