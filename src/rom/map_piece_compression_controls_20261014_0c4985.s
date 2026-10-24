.setcpu "65816"
.segment "CODE"
.org $4985
map_control_0c4985:
    .byte $E1 ; previous-row copy count
    .byte $ED ; backreference distance high bits
    .byte $04 ; distance low bit/count
