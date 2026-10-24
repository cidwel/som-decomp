.setcpu "65816"
.segment "CODE"
.org $F04C
map_control_0ff04c:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
