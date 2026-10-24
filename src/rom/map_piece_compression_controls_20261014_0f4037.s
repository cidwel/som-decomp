.setcpu "65816"
.segment "CODE"
.org $4037
map_control_0f4037:
    .byte $F1 ; progressive-copy count
    .byte $E0 ; previous-row copy escape
    .byte $60 ; row-distance/count
