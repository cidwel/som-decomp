.setcpu "65816"
.segment "CODE"
.org $D197
map_control_0ed197:
    .byte $F1 ; progressive-copy count
    .byte $E0 ; previous-row copy escape
    .byte $11 ; row-distance/count
