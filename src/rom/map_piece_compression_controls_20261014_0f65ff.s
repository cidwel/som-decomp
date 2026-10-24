.setcpu "65816"
.segment "CODE"
.org $65FF
map_control_0f65ff:
    .byte $E1 ; previous-row copy count
