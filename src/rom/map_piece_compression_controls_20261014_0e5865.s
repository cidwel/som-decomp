.setcpu "65816"
.segment "CODE"
.org $5865
map_control_0e5865:
    .byte $F2 ; progressive-copy count
    .byte $E0 ; previous-row copy escape
    .byte $0E ; row-distance/count
