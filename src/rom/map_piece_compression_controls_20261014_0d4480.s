.setcpu "65816"
.segment "CODE"
.org $4480
map_control_0d4480:
    .byte $E8 ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
