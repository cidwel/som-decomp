.setcpu "65816"
.segment "CODE"
.org $22FF
map_control_0f22ff:
    .byte $E1 ; previous-row copy count
