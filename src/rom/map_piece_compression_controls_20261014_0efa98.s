.setcpu "65816"
.segment "CODE"
.org $FA98
map_control_0efa98:
    .byte $E8 ; backreference distance high bits
    .byte $0F ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
