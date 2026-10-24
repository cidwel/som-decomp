.setcpu "65816"
.segment "CODE"
.org $580E
map_control_0e580e:
    .byte $F2 ; progressive-copy count
    .byte $E0 ; previous-row copy escape
    .byte $14 ; row-distance/count
