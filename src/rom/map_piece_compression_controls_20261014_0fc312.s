.setcpu "65816"
.segment "CODE"
.org $C312
map_control_0fc312:
    .byte $E8 ; backreference distance high bits
    .byte $0F ; distance low bit/count
    .byte $E5 ; previous-row copy count
