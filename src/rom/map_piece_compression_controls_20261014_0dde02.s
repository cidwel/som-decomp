.setcpu "65816"
.segment "CODE"
.org $DE02
map_control_0dde02:
    .byte $E5 ; previous-row copy count
