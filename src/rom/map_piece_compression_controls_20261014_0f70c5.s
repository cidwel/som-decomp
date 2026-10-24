.setcpu "65816"
.segment "CODE"
.org $70C5
map_control_0f70c5:
    .byte $E2 ; previous-row copy count
    .byte $E9 ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $E5 ; previous-row copy count
