.setcpu "65816"
.segment "CODE"
.org $828C
map_control_0d828c:
    .byte $F1 ; progressive-copy count
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
