.setcpu "65816"
.segment "CODE"
.org $F5E4
map_control_0ef5e4:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
