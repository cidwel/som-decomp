.setcpu "65816"
.segment "CODE"
.org $EE98
map_control_0eee98:
    .byte $F1 ; progressive-copy count
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
