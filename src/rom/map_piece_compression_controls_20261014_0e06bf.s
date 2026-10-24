.setcpu "65816"
.segment "CODE"
.org $06BF
map_control_0e06bf:
    .byte $F2 ; progressive-copy count
    .byte $E0 ; previous-row copy escape
    .byte $82 ; row-distance/count
