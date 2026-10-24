.setcpu "65816"
.segment "CODE"
.org $41CB
map_control_0f41cb:
    .byte $E1 ; previous-row copy count
