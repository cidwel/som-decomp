.setcpu "65816"
.segment "CODE"
.org $D3CC
map_control_0fd3cc:
    .byte $ED ; backreference distance high bits
    .byte $04 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $11 ; distance low bit/count
    .byte $E1 ; previous-row copy count
    .byte $E8 ; backreference distance high bits
    .byte $0C ; distance low bit/count
    .byte $E5 ; previous-row copy count
    .byte $E8 ; backreference distance high bits
    .byte $1C ; distance low bit/count
