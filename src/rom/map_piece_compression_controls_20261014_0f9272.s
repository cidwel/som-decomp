.setcpu "65816"
.segment "CODE"
.org $9272
map_control_0f9272:
    .byte $F2 ; progressive-copy count
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
