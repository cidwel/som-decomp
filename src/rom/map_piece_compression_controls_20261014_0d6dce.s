.setcpu "65816"
.segment "CODE"
.org $6DCE
map_control_0d6dce:
    .byte $E5 ; previous-row copy count
    .byte $ED ; backreference distance high bits
    .byte $84 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $8A ; distance low bit/count
    .byte $E1 ; previous-row copy count
