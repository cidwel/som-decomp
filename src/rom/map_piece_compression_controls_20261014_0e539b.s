.setcpu "65816"
.segment "CODE"
.org $539B
map_control_0e539b:
    .byte $F1 ; progressive-copy count
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
