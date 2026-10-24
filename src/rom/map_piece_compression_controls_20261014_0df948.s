.setcpu "65816"
.segment "CODE"
.org $F948
map_control_0df948:
    .byte $F5 ; progressive-copy count
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
