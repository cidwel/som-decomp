.setcpu "65816"
.segment "CODE"
.org $7C64
map_control_0f7c64:
    .byte $E5 ; previous-row copy count
