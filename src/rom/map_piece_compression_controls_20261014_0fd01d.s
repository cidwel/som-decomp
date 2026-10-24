.setcpu "65816"
.segment "CODE"
.org $D01D
map_control_0fd01d:
    .byte $E1 ; previous-row copy count
