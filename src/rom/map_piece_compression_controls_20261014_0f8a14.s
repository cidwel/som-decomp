.setcpu "65816"
.segment "CODE"
.org $8A14
map_control_0f8a14:
    .byte $E8 ; backreference distance high bits
    .byte $09 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
    .byte $EB ; backreference distance high bits
    .byte $83 ; distance low bit/count
