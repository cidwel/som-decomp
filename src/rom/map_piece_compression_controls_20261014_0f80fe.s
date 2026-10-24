.setcpu "65816"
.segment "CODE"
.org $80FE
map_control_0f80fe:
    .byte $F1 ; progressive-copy count
