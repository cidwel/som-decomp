.setcpu "65816"
.segment "CODE"
.org $AA3E
map_control_0faa3e:
    .byte $F1 ; progressive-copy count
    .byte $E0 ; previous-row copy escape
    .byte $19 ; row-distance/count
