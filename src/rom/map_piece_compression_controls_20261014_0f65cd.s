.setcpu "65816"
.segment "CODE"
.org $65CD
map_control_0f65cd:
    .byte $E5 ; previous-row copy count
