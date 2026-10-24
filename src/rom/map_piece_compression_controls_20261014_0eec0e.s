.setcpu "65816"
.segment "CODE"
.org $EC0E
map_control_0eec0e:
    .byte $E8 ; backreference distance high bits
    .byte $0C ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $11 ; row-distance/count
