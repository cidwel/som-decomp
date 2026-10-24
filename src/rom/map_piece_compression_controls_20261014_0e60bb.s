.setcpu "65816"
.segment "CODE"
.org $60BB
map_control_0e60bb:
    .byte $E5 ; previous-row copy count
