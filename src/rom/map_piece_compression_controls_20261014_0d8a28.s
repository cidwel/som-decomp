.setcpu "65816"
.segment "CODE"
.org $8A28
map_control_0d8a28:
    .byte $F1 ; progressive-copy count
    .byte $E0 ; previous-row copy escape
    .byte $8B ; row-distance/count
