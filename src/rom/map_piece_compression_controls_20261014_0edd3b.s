.setcpu "65816"
.segment "CODE"
.org $DD3B
map_control_0edd3b:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
