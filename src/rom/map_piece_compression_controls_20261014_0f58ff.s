.setcpu "65816"
.segment "CODE"
.org $58FF
map_control_0f58ff:
    .byte $E6 ; previous-row copy count
