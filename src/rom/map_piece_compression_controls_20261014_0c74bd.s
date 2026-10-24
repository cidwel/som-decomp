.setcpu "65816"
.segment "CODE"
.org $74BD
map_control_0c74bd:
    .byte $ED ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $E1 ; previous-row copy count
