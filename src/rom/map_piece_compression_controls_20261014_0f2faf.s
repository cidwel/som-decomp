.setcpu "65816"
.segment "CODE"
.org $2FAF
map_control_0f2faf:
    .byte $E9 ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $E1 ; previous-row copy count
    .byte $E8 ; backreference distance high bits
    .byte $10 ; distance low bit/count
