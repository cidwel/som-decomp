.setcpu "65816"
.segment "CODE"
.org $D5EA
map_control_0ed5ea:
    .byte $EA ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $E9 ; backreference distance high bits
    .byte $02 ; distance low bit/count
