.setcpu "65816"
.segment "CODE"
.org $77BB
map_control_0c77bb:
    .byte $F3 ; progressive-copy count
    .byte $E3 ; previous-row copy count
