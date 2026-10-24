.setcpu "65816"
.segment "CODE"
.org $C536
map_control_0fc536:
    .byte $E0 ; previous-row copy escape
    .byte $14 ; row-distance/count
    .byte $F1 ; progressive-copy count
