.setcpu "65816"
.segment "CODE"
.org $934C
map_control_0d934c:
    .byte $F1 ; progressive-copy count
    .byte $E0 ; previous-row copy escape
    .byte $4D ; row-distance/count
