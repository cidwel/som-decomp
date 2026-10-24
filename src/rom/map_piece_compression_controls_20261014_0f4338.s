.setcpu "65816"
.segment "CODE"
.org $4338
map_control_0f4338:
    .byte $E2 ; previous-row copy count
    .byte $F2 ; progressive-copy count
