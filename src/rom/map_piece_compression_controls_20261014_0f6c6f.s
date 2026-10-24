.setcpu "65816"
.segment "CODE"
.org $6C6F
map_control_0f6c6f:
    .byte $E2 ; previous-row copy count
    .byte $ED ; backreference distance high bits
    .byte $84 ; distance low bit/count
    .byte $EA ; backreference distance high bits
    .byte $8B ; distance low bit/count
    .byte $E1 ; previous-row copy count
