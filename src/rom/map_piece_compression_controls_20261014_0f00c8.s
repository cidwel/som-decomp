.setcpu "65816"
.segment "CODE"
.org $00C8
map_control_0f00c8:
    .byte $E0 ; previous-row copy escape
    .byte $8C ; row-distance/count
    .byte $E2 ; previous-row copy count
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $85 ; distance low bit/count
