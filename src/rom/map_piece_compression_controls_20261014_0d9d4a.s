.setcpu "65816"
.segment "CODE"
.org $9D4A
map_control_0d9d4a:
    .byte $F1 ; progressive-copy count
    .byte $E0 ; previous-row copy escape
    .byte $10 ; row-distance/count
