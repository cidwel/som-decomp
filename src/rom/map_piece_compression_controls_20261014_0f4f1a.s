.setcpu "65816"
.segment "CODE"
.org $4F1A
map_control_0f4f1a:
    .byte $F1 ; progressive-copy count
    .byte $E0 ; previous-row copy escape
    .byte $11 ; row-distance/count
