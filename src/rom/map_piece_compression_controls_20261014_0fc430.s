.setcpu "65816"
.segment "CODE"
.org $C430
map_control_0fc430:
    .byte $EA ; backreference distance high bits
    .byte $08 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
