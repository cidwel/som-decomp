.setcpu "65816"
.segment "CODE"
.org $7A6B
map_control_0e7a6b:
    .byte $E9 ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $08 ; distance low bit/count
    .byte $EE ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $7F ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $7E ; row-distance/count
