.setcpu "65816"
.segment "CODE"
.org $4B4B
map_control_0f4b4b:
    .byte $E8 ; backreference distance high bits
    .byte $0B ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
