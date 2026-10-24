.setcpu "65816"
.segment "CODE"
.org $D615
map_control_0dd615:
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
