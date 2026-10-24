.setcpu "65816"
.segment "CODE"
.org $4129
map_control_0f4129:
    .byte $F1 ; progressive-copy count
    .byte $E6 ; previous-row copy count
