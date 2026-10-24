.setcpu "65816"
.segment "CODE"
.org $8C0B
map_control_0c8c0b:
    .byte $F1 ; progressive-copy count
    .byte $E0 ; previous-row copy escape
    .byte $17 ; row-distance/count
