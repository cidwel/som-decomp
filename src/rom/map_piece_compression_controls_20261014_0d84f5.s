.setcpu "65816"
.segment "CODE"
.org $84F5
map_control_0d84f5:
    .byte $EF ; backreference distance high bits
    .byte $88 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $39 ; distance low bit/count
    .byte $E2 ; previous-row copy count
