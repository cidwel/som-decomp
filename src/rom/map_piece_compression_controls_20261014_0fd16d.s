.setcpu "65816"
.segment "CODE"
.org $D16D
map_control_0fd16d:
    .byte $E1 ; previous-row copy count
