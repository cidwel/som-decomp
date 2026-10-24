.setcpu "65816"
.segment "CODE"
.org $F557
map_control_0ff557:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
