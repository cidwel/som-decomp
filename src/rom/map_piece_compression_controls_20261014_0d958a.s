.setcpu "65816"
.segment "CODE"
.org $958A
map_control_0d958a:
    .byte $E8 ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $ED ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $88 ; distance low bit/count
    .byte $E6 ; previous-row copy count
