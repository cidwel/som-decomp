.setcpu "65816"
.segment "CODE"
.org $6C33
map_control_0f6c33:
    .byte $EA ; backreference distance high bits
    .byte $8B ; distance low bit/count
    .byte $E5 ; previous-row copy count
    .byte $ED ; backreference distance high bits
    .byte $83 ; distance low bit/count
