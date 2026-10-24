.setcpu "65816"
.segment "CODE"
.org $0B08
map_control_0f0b08:
    .byte $E7 ; previous-row copy count
