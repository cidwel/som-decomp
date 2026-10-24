.setcpu "65816"
.segment "CODE"
.org $6615
map_control_0d6615:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
