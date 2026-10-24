.setcpu "65816"
.segment "CODE"
.org $CD04
map_control_0dcd04:
    .byte $E3 ; previous-row copy count
