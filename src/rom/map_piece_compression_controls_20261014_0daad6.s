.setcpu "65816"
.segment "CODE"
.org $AAD6
map_control_0daad6:
    .byte $F2 ; progressive-copy count
    .byte $E0 ; previous-row copy escape
    .byte $87 ; row-distance/count
