.setcpu "65816"
.segment "CODE"
.org $F5BB
map_control_0ef5bb:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
