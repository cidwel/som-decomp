.setcpu "65816"
.segment "CODE"
.org $71C6
map_control_0d71c6:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
