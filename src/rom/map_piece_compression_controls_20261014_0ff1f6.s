.setcpu "65816"
.segment "CODE"
.org $F1F6
map_control_0ff1f6:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
