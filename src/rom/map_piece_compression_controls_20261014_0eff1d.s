.setcpu "65816"
.segment "CODE"
.org $FF1D
map_control_0eff1d:
    .byte $E1 ; previous-row copy count
