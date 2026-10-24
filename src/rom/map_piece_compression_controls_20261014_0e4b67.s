.setcpu "65816"
.segment "CODE"
.org $4B67
map_control_0e4b67:
    .byte $F1 ; progressive-copy count
    .byte $E0 ; previous-row copy escape
    .byte $83 ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
