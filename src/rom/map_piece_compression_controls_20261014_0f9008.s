.setcpu "65816"
.segment "CODE"
.org $9008
map_control_0f9008:
    .byte $E3 ; previous-row copy count
