.setcpu "65816"
.segment "CODE"
.org $DFD9
map_control_0edfd9:
    .byte $F2 ; progressive-copy count
    .byte $E0 ; previous-row copy escape
    .byte $26 ; row-distance/count
