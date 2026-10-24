.setcpu "65816"
.segment "CODE"
.org $85C0
map_control_0d85c0:
    .byte $F1 ; progressive-copy count
    .byte $E7 ; previous-row copy count
