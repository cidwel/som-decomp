.setcpu "65816"
.segment "CODE"
.org $FF54
map_control_0eff54:
    .byte $E3 ; previous-row copy count
