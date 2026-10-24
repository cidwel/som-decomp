.setcpu "65816"
.segment "CODE"
.org $76FD
map_control_0f76fd:
    .byte $E9 ; backreference distance high bits
    .byte $8D ; distance low bit/count
    .byte $E3 ; previous-row copy count
