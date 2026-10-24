.setcpu "65816"
.segment "CODE"
.org $0F65
map_control_0f0f65:
    .byte $E3 ; previous-row copy count
