.setcpu "65816"
.segment "CODE"
.org $0FE4
map_control_0c0fe4:
    .byte $EC ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
