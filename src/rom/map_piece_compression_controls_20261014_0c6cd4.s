.setcpu "65816"
.segment "CODE"
.org $6CD4
map_control_0c6cd4:
    .byte $F1 ; progressive-copy count
    .byte $E0 ; previous-row copy escape
    .byte $39 ; row-distance/count
