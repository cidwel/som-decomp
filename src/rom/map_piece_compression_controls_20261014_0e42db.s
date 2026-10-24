.setcpu "65816"
.segment "CODE"
.org $42DB
map_control_0e42db:
    .byte $F1 ; progressive-copy count
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
