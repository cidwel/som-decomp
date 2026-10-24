.setcpu "65816"
.segment "CODE"
.org $0F80
map_control_0e0f80:
    .byte $E6 ; previous-row copy count
