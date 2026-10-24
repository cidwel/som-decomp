.setcpu "65816"
.segment "CODE"
.org $87E5
map_control_0d87e5:
    .byte $F1 ; progressive-copy count
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
