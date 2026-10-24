.setcpu "65816"
.segment "CODE"
.org $7B5D
map_control_0e7b5d:
    .byte $F1 ; progressive-copy count
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
