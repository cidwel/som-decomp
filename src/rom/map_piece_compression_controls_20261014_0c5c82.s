.setcpu "65816"
.segment "CODE"
.org $5C82
map_control_0c5c82:
    .byte $ED ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $E1 ; previous-row copy count
