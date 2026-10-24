.setcpu "65816"
.segment "CODE"
.org $2760
map_control_0f2760:
    .byte $ED ; backreference distance high bits
    .byte $07 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $08 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
