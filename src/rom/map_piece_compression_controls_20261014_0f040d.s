.setcpu "65816"
.segment "CODE"
.org $040D
map_control_0f040d:
    .byte $E4 ; previous-row copy count
