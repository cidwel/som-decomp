.setcpu "65816"
.segment "CODE"
.org $704B
map_control_0c704b:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
