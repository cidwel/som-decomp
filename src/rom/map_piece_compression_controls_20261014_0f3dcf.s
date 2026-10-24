.setcpu "65816"
.segment "CODE"
.org $3DCF
map_control_0f3dcf:
    .byte $F1 ; progressive-copy count
