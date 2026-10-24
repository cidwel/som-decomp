.setcpu "65816"
.segment "CODE"
.org $FF33
map_control_0eff33:
    .byte $E1 ; previous-row copy count
