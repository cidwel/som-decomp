.setcpu "65816"
.segment "CODE"
.org $2A0F
map_control_0e2a0f:
    .byte $E0 ; previous-row copy escape
    .byte $83 ; row-distance/count
    .byte $F1 ; progressive-copy count
