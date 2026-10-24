.setcpu "65816"
.segment "CODE"
.org $C176
map_control_0fc176:
    .byte $EA ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $0D ; distance low bit/count
