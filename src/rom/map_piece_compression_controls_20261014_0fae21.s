.setcpu "65816"
.segment "CODE"
.org $AE21
map_control_0fae21:
    .byte $E3 ; previous-row copy count
