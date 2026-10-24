.setcpu "65816"
.segment "CODE"
.org $A856
map_control_0ea856:
    .byte $F1 ; progressive-copy count
    .byte $E0 ; previous-row copy escape
    .byte $16 ; row-distance/count
