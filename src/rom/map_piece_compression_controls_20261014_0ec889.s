.setcpu "65816"
.segment "CODE"
.org $C889
map_control_0ec889:
    .byte $F1 ; progressive-copy count
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
