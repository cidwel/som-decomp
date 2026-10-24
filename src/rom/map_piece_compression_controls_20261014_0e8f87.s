.setcpu "65816"
.segment "CODE"
.org $8F87
map_control_0e8f87:
    .byte $E8 ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
