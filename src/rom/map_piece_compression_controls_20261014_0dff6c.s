.setcpu "65816"
.segment "CODE"
.org $FF6C
map_control_0dff6c:
    .byte $E7 ; previous-row copy count
