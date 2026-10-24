.setcpu "65816"
.segment "CODE"
.org $39F8
map_control_0d39f8:
    .byte $E8 ; backreference distance high bits
    .byte $8B ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
