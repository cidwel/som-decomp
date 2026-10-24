.setcpu "65816"
.segment "CODE"
.org $D18A
map_control_0ed18a:
    .byte $F1 ; progressive-copy count
    .byte $E0 ; previous-row copy escape
    .byte $0E ; row-distance/count
