.setcpu "65816"
.segment "CODE"
.org $7FBC
map_control_0f7fbc:
    .byte $E7 ; previous-row copy count
