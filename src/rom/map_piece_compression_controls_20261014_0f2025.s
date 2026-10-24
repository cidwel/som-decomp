.setcpu "65816"
.segment "CODE"
.org $2025
map_control_0f2025:
    .byte $E9 ; backreference distance high bits
    .byte $03 ; distance low bit/count
    .byte $EF ; backreference distance high bits
    .byte $06 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
