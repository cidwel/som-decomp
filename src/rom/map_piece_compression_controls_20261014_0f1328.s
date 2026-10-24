.setcpu "65816"
.segment "CODE"
.org $1328
map_control_0f1328:
    .byte $E8 ; backreference distance high bits
    .byte $0B ; distance low bit/count
    .byte $E5 ; previous-row copy count
    .byte $E8 ; backreference distance high bits
    .byte $28 ; distance low bit/count
