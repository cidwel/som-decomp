.setcpu "65816"
.segment "CODE"
.org $11BB
map_control_0f11bb:
    .byte $E7 ; previous-row copy count
