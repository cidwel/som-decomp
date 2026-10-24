.setcpu "65816"
.segment "CODE"
.org $ED00
map_control_0ded00:
    .byte $E1 ; previous-row copy count
