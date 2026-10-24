.setcpu "65816"
.segment "CODE"
.org $8CEC
map_control_0c8cec:
    .byte $F1 ; progressive-copy count
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
