.setcpu "65816"
.segment "CODE"
.org $7C8C
map_control_0e7c8c:
    .byte $F1 ; progressive-copy count
    .byte $E0 ; previous-row copy escape
    .byte $13 ; row-distance/count
