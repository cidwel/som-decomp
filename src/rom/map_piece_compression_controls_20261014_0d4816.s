.setcpu "65816"
.segment "CODE"
.org $4816
map_control_0d4816:
    .byte $E8 ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $E5 ; previous-row copy count
    .byte $ED ; backreference distance high bits
    .byte $8B ; distance low bit/count
