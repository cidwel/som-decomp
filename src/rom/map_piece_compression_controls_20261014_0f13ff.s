.setcpu "65816"
.segment "CODE"
.org $13FF
map_control_0f13ff:
    .byte $E2 ; previous-row copy count
