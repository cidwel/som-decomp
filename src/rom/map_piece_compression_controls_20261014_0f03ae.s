.setcpu "65816"
.segment "CODE"
.org $03AE
map_control_0f03ae:
    .byte $ED ; backreference distance high bits
    .byte $0D ; distance low bit/count
    .byte $EA ; backreference distance high bits
    .byte $02 ; distance low bit/count
