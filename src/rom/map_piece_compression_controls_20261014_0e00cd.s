.setcpu "65816"
.segment "CODE"
.org $00CD
map_control_0e00cd:
    .byte $E5 ; previous-row copy count
