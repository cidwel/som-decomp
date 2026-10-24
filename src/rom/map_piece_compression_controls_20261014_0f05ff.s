.setcpu "65816"
.segment "CODE"
.org $05FF
map_control_0f05ff:
    .byte $E3 ; previous-row copy count
