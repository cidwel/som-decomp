.setcpu "65816"
.segment "CODE"
.org $5DC6
map_control_0f5dc6:
    .byte $E8 ; backreference distance high bits
    .byte $11 ; distance low bit/count
    .byte $E3 ; previous-row copy count
    .byte $E8 ; backreference distance high bits
    .byte $22 ; distance low bit/count
