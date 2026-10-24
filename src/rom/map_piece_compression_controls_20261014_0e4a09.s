.setcpu "65816"
.segment "CODE"
.org $4A09
map_control_0e4a09:
    .byte $F2 ; progressive-copy count
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
