.setcpu "65816"
.segment "CODE"
.org $E49B
map_control_0fe49b:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
