.setcpu "65816"
.segment "CODE"
.org $ECDB
map_control_0decdb:
    .byte $F1 ; progressive-copy count
