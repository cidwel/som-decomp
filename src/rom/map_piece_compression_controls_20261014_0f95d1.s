.setcpu "65816"
.segment "CODE"
.org $95D1
map_control_0f95d1:
    .byte $E8 ; backreference distance high bits
    .byte $08 ; distance low bit/count
    .byte $ED ; backreference distance high bits
    .byte $8B ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $7F ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $41 ; row-distance/count
