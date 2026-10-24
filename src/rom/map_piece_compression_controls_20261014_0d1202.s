.setcpu "65816"
.segment "CODE"
.org $1202
map_control_0d1202:
    .byte $F1 ; progressive-copy count
    .byte $E0 ; previous-row copy escape
    .byte $9B ; row-distance/count
