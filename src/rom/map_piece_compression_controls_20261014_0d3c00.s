.setcpu "65816"
.segment "CODE"
.org $3C00
map_control_0d3c00:
    .byte $EF ; backreference distance high bits
    .byte $06 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $E5 ; previous-row copy count
    .byte $EC ; backreference distance high bits
    .byte $82 ; distance low bit/count
