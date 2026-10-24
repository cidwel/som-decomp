.setcpu "65816"
.segment "CODE"
.org $3E8C
map_control_0e3e8c:
    .byte $F1 ; progressive-copy count
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
