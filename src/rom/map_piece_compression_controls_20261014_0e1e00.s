.setcpu "65816"
.segment "CODE"
.org $1E00
map_control_0e1e00:
    .byte $E1 ; previous-row copy count
