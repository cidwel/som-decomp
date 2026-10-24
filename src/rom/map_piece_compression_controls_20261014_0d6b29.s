.setcpu "65816"
.segment "CODE"
.org $6B29
map_control_0d6b29:
    .byte $E1 ; previous-row copy count
    .byte $F2 ; progressive-copy count
