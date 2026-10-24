.setcpu "65816"
.segment "CODE"
.org $F870
map_control_0df870:
    .byte $F7 ; progressive-copy count
    .byte $E0 ; previous-row copy escape
    .byte $82 ; row-distance/count
