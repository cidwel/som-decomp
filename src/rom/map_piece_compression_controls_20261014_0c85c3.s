.setcpu "65816"
.segment "CODE"
.org $85C3
map_control_0c85c3:
    .byte $F1 ; progressive-copy count
    .byte $E0 ; previous-row copy escape
    .byte $3C ; row-distance/count
