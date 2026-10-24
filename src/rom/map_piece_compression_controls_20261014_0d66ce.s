.setcpu "65816"
.segment "CODE"
.org $66CE
map_control_0d66ce:
    .byte $EA ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $17 ; distance low bit/count
