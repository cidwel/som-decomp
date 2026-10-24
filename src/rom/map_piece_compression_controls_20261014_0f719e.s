.setcpu "65816"
.segment "CODE"
.org $719E
map_control_0f719e:
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $0B ; distance low bit/count
