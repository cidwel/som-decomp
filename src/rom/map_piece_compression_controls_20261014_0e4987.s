.setcpu "65816"
.segment "CODE"
.org $4987
map_control_0e4987:
    .byte $F1 ; progressive-copy count
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
