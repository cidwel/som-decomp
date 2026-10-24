.setcpu "65816"
.segment "CODE"
.org $FF60
map_control_0dff60:
    .byte $E2 ; previous-row copy count
