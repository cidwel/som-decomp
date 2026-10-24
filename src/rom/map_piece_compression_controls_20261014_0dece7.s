.setcpu "65816"
.segment "CODE"
.org $ECE7
map_control_0dece7:
    .byte $F1 ; progressive-copy count
    .byte $E0 ; previous-row copy escape
    .byte $1F ; row-distance/count
