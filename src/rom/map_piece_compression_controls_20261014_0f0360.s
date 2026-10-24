.setcpu "65816"
.segment "CODE"
.org $0360
map_control_0f0360:
    .byte $EF ; backreference distance high bits
    .byte $06 ; distance low bit/count
    .byte $ED ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $EF ; backreference distance high bits
    .byte $06 ; distance low bit/count
    .byte $E6 ; previous-row copy count
