.setcpu "65816"
.segment "CODE"
.org $A19A
map_control_0fa19a:
    .byte $F1 ; progressive-copy count
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
