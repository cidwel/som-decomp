.setcpu "65816"
.segment "CODE"
.org $8041
map_control_0f8041:
    .byte $E5 ; previous-row copy count
