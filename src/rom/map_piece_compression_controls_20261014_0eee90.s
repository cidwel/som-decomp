.setcpu "65816"
.segment "CODE"
.org $EE90
map_control_0eee90:
    .byte $F1 ; progressive-copy count
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
