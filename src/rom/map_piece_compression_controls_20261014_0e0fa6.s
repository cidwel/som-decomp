.setcpu "65816"
.segment "CODE"
.org $0FA6
map_control_0e0fa6:
    .byte $ED ; backreference distance high bits
    .byte $87 ; distance low bit/count
    .byte $EA ; backreference distance high bits
    .byte $04 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $83 ; row-distance/count
