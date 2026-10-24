.setcpu "65816"
.segment "CODE"
.org $ED6E
map_control_0eed6e:
    .byte $E8 ; backreference distance high bits
    .byte $17 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
