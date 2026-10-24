.setcpu "65816"
.segment "CODE"
.org $071B
map_control_0e071b:
    .byte $F3 ; progressive-copy count
    .byte $EE ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $EA ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $EB ; backreference distance high bits
    .byte $83 ; distance low bit/count
