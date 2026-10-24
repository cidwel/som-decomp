.setcpu "65816"
.segment "CODE"
.org $33DA
map_control_0f33da:
    .byte $EF ; backreference distance high bits
    .byte $87 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $0C ; distance low bit/count
    .byte $E1 ; previous-row copy count
