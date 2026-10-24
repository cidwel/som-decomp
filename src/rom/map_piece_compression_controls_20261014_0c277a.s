.setcpu "65816"
.segment "CODE"
.org $277A
map_control_0c277a:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
