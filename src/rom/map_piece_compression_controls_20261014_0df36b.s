.setcpu "65816"
.segment "CODE"
.org $F36B
map_control_0df36b:
    .byte $F1 ; progressive-copy count
    .byte $E0 ; previous-row copy escape
    .byte $84 ; row-distance/count
