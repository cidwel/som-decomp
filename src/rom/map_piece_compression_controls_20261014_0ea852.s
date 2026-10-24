.setcpu "65816"
.segment "CODE"
.org $A852
map_control_0ea852:
    .byte $F1 ; progressive-copy count
    .byte $E0 ; previous-row copy escape
    .byte $1A ; row-distance/count
