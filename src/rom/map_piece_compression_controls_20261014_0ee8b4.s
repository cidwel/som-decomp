.setcpu "65816"
.segment "CODE"
.org $E8B4
map_control_0ee8b4:
    .byte $EF ; backreference distance high bits
    .byte $8B ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0E ; row-distance/count
