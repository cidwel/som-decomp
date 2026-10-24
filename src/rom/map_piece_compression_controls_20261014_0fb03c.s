.setcpu "65816"
.segment "CODE"
.org $B03C
map_control_0fb03c:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
