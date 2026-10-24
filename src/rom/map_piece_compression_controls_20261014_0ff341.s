.setcpu "65816"
.segment "CODE"
.org $F341
map_control_0ff341:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
