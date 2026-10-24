.setcpu "65816"
.segment "CODE"
.org $FF50
map_control_0dff50:
    .byte $E2 ; previous-row copy count
