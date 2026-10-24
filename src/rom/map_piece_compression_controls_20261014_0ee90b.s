.setcpu "65816"
.segment "CODE"
.org $E90B
map_control_0ee90b:
    .byte $E8 ; backreference distance high bits
    .byte $0E ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $1C ; row-distance/count
