.setcpu "65816"
.segment "CODE"
.org $F0AF
map_control_0ef0af:
    .byte $E1 ; previous-row copy count
    .byte $E9 ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $28 ; distance low bit/count
