.setcpu "65816"
.segment "CODE"
.org $F08C
map_control_0ff08c:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
