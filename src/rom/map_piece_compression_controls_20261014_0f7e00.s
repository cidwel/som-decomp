.setcpu "65816"
.segment "CODE"
.org $7E00
map_control_0f7e00:
    .byte $E6 ; previous-row copy count
