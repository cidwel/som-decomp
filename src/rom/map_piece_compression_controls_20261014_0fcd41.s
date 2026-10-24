.setcpu "65816"
.segment "CODE"
.org $CD41
map_control_0fcd41:
    .byte $E7 ; previous-row copy count
