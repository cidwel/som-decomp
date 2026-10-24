.setcpu "65816"
.segment "CODE"
.org $5280
map_control_0f5280:
    .byte $F1 ; progressive-copy count
    .byte $E7 ; previous-row copy count
