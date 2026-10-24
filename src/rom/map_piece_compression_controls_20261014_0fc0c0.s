.setcpu "65816"
.segment "CODE"
.org $C0C0
map_control_0fc0c0:
    .byte $E3 ; previous-row copy count
    .byte $E8 ; backreference distance high bits
    .byte $08 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
