.setcpu "65816"
.segment "CODE"
.org $87E1
map_control_0d87e1:
    .byte $F1 ; progressive-copy count
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
