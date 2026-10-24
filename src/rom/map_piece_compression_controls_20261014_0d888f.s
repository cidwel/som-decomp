.setcpu "65816"
.segment "CODE"
.org $888F
map_control_0d888f:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
