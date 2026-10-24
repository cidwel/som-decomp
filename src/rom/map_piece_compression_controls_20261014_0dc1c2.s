.setcpu "65816"
.segment "CODE"
.org $C1C2
map_control_0dc1c2:
    .byte $F1 ; progressive-copy count
    .byte $E0 ; previous-row copy escape
    .byte $83 ; row-distance/count
