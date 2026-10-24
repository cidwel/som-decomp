.setcpu "65816"
.segment "CODE"
.org $FF13
map_control_0eff13:
    .byte $F1 ; progressive-copy count
