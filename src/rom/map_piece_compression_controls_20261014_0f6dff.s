.setcpu "65816"
.segment "CODE"
.org $6DFF
map_control_0f6dff:
    .byte $E1 ; previous-row copy count
