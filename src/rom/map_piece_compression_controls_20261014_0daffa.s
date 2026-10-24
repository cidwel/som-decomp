.setcpu "65816"
.segment "CODE"
.org $AFFA
map_control_0daffa:
    .byte $F1 ; progressive-copy count
