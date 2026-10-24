.setcpu "65816"
.segment "CODE"
.org $506B
map_control_0e506b:
    .byte $F2 ; progressive-copy count
    .byte $E0 ; previous-row copy escape
    .byte $16 ; row-distance/count
