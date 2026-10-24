.setcpu "65816"
.segment "CODE"
.org $D798
map_control_0dd798:
    .byte $F1 ; progressive-copy count
    .byte $E0 ; previous-row copy escape
    .byte $11 ; row-distance/count
