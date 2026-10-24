.setcpu "65816"
.segment "CODE"
.org $5135
map_control_0f5135:
    .byte $F1 ; progressive-copy count
    .byte $E0 ; previous-row copy escape
    .byte $13 ; row-distance/count
