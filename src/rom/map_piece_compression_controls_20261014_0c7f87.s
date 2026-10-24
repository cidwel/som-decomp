.setcpu "65816"
.segment "CODE"
.org $7F87
map_control_0c7f87:
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $0A ; distance low bit/count
