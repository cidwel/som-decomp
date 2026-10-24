.setcpu "65816"
.segment "CODE"
.org $F0F8
map_control_0ef0f8:
    .byte $E5 ; previous-row copy count
