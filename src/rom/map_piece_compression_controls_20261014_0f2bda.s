.setcpu "65816"
.segment "CODE"
.org $2BDA
map_control_0f2bda:
    .byte $E7 ; previous-row copy count
