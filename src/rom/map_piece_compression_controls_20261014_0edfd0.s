.setcpu "65816"
.segment "CODE"
.org $DFD0
map_control_0edfd0:
    .byte $F4 ; progressive-copy count
    .byte $E0 ; previous-row copy escape
    .byte $27 ; row-distance/count
