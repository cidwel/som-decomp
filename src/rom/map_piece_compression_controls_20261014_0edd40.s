.setcpu "65816"
.segment "CODE"
.org $DD40
map_control_0edd40:
    .byte $E3 ; previous-row copy count
