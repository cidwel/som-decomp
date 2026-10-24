.setcpu "65816"
.segment "CODE"
.org $05E9
map_control_0f05e9:
    .byte $F1 ; progressive-copy count
    .byte $E0 ; previous-row copy escape
    .byte $0E ; row-distance/count
