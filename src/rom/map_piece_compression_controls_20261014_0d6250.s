.setcpu "65816"
.segment "CODE"
.org $6250
map_control_0d6250:
    .byte $E6 ; previous-row copy count
