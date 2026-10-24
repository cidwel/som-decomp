.setcpu "65816"
.segment "CODE"
.org $AA6A
map_control_0daa6a:
    .byte $E8 ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $0B ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
