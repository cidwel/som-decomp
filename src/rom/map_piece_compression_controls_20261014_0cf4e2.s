.setcpu "65816"
.segment "CODE"
.org $F4E2
map_control_0cf4e2:
    .byte $F2 ; progressive-copy count
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
