.setcpu "65816"
.segment "CODE"
.org $03CB
map_control_0e03cb:
    .byte $E1 ; previous-row copy count
