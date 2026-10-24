.setcpu "65816"
.segment "CODE"
.org $F5AA
map_control_0ef5aa:
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
