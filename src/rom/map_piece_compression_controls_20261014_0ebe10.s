.setcpu "65816"
.segment "CODE"
.org $BE10
map_control_0ebe10:
    .byte $F1 ; progressive-copy count
    .byte $E0 ; previous-row copy escape
    .byte $8B ; row-distance/count
