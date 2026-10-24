.setcpu "65816"
.segment "CODE"
.org $C22B
map_control_0ec22b:
    .byte $F1 ; progressive-copy count
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
