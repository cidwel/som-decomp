.setcpu "65816"
.segment "CODE"
.org $42EE
map_control_0e42ee:
    .byte $F2 ; progressive-copy count
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
