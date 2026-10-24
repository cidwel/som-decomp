.setcpu "65816"
.segment "CODE"
.org $F4FA
map_control_0cf4fa:
    .byte $F1 ; progressive-copy count
    .byte $E0 ; previous-row copy escape
    .byte $83 ; row-distance/count
