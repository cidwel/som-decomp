.setcpu "65816"
.segment "CODE"
.org $B89E
map_control_0db89e:
    .byte $F2 ; progressive-copy count
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
