.setcpu "65816"
.segment "CODE"
.org $60CD
map_control_0c60cd:
    .byte $F2 ; progressive-copy count
