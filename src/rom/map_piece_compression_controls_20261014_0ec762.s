.setcpu "65816"
.segment "CODE"
.org $C762
map_control_0ec762:
    .byte $E8 ; backreference distance high bits
    .byte $88 ; distance low bit/count
    .byte $E1 ; previous-row copy count
    .byte $E9 ; backreference distance high bits
    .byte $83 ; distance low bit/count
