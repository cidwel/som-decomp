.setcpu "65816"
.segment "CODE"
.org $5F10
map_control_0f5f10:
    .byte $E5 ; previous-row copy count
