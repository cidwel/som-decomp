.setcpu "65816"
.segment "CODE"
.org $F5B0
map_control_0ef5b0:
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
