.setcpu "65816"
.segment "CODE"
.org $1EFD
map_control_0f1efd:
    .byte $E3 ; previous-row copy count
