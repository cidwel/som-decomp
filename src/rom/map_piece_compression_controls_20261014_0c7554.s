.setcpu "65816"
.segment "CODE"
.org $7554
map_control_0c7554:
    .byte $F1 ; progressive-copy count
    .byte $EE ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $EF ; backreference distance high bits
    .byte $04 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $0C ; distance low bit/count
