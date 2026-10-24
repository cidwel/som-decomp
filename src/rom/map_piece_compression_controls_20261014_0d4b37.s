.setcpu "65816"
.segment "CODE"
.org $4B37
map_control_0d4b37:
    .byte $E8 ; backreference distance high bits
    .byte $87 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $88 ; row-distance/count
    .byte $E2 ; previous-row copy count
    .byte $E8 ; backreference distance high bits
    .byte $15 ; distance low bit/count
