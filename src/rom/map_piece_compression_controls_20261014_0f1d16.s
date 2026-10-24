.setcpu "65816"
.segment "CODE"
.org $1D16
map_control_0f1d16:
    .byte $E1 ; previous-row copy count
