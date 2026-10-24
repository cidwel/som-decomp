.setcpu "65816"
.segment "CODE"
.org $67A7
map_control_0c67a7:
    .byte $F1 ; progressive-copy count
    .byte $E0 ; previous-row copy escape
    .byte $13 ; row-distance/count
