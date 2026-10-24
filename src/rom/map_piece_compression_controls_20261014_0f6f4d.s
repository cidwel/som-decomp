.setcpu "65816"
.segment "CODE"
.org $6F4D
map_control_0f6f4d:
    .byte $E8 ; backreference distance high bits
    .byte $33 ; distance low bit/count
    .byte $E7 ; previous-row copy count
    .byte $E8 ; backreference distance high bits
    .byte $37 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $7A ; row-distance/count
