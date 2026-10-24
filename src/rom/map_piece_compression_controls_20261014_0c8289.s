.setcpu "65816"
.segment "CODE"
.org $8289
map_control_0c8289:
    .byte $EA ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $0C ; distance low bit/count
    .byte $EF ; backreference distance high bits
    .byte $8F ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $5D ; distance low bit/count
