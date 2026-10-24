.setcpu "65816"
.segment "CODE"
.org $DC14
map_control_0ddc14:
    .byte $F1 ; progressive-copy count
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $8F ; row-distance/count
