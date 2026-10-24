.setcpu "65816"
.segment "CODE"
.org $3183
map_control_0e3183:
    .byte $E9 ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $08 ; distance low bit/count
    .byte $E2 ; previous-row copy count
