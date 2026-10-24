.setcpu "65816"
.segment "CODE"
.org $1DDC
map_control_0d1ddc:
    .byte $E3 ; previous-row copy count
