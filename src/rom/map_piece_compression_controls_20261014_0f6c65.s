.setcpu "65816"
.segment "CODE"
.org $6C65
map_control_0f6c65:
    .byte $ED ; backreference distance high bits
    .byte $84 ; distance low bit/count
    .byte $E7 ; previous-row copy count
