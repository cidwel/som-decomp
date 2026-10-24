.setcpu "65816"
.segment "CODE"
.org $71D6
map_control_0f71d6:
    .byte $F1 ; progressive-copy count
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
