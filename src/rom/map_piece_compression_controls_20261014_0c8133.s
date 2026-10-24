.setcpu "65816"
.segment "CODE"
.org $8133
map_control_0c8133:
    .byte $F1 ; progressive-copy count
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
