.setcpu "65816"
.segment "CODE"
.org $8DBD
map_control_0f8dbd:
    .byte $E8 ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
