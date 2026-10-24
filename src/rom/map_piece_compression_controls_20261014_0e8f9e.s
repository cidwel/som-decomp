.setcpu "65816"
.segment "CODE"
.org $8F9E
map_control_0e8f9e:
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $0B ; distance low bit/count
