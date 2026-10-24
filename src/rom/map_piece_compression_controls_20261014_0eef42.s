.setcpu "65816"
.segment "CODE"
.org $EF42
map_control_0eef42:
    .byte $F1 ; progressive-copy count
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
