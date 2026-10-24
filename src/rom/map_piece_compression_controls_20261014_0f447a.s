.setcpu "65816"
.segment "CODE"
.org $447A
map_control_0f447a:
    .byte $F1 ; progressive-copy count
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
