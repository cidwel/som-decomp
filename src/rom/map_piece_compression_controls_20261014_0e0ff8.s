.setcpu "65816"
.segment "CODE"
.org $0FF8
map_control_0e0ff8:
    .byte $E0 ; previous-row copy escape
    .byte $12 ; row-distance/count
