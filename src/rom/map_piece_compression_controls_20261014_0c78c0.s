.setcpu "65816"
.segment "CODE"
.org $78C0
map_control_0c78c0:
    .byte $F1 ; progressive-copy count
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
