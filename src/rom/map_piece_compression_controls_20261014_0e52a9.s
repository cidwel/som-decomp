.setcpu "65816"
.segment "CODE"
.org $52A9
map_control_0e52a9:
    .byte $E0 ; previous-row copy escape
    .byte $2B ; row-distance/count
    .byte $F1 ; progressive-copy count
    .byte $E3 ; previous-row copy count
