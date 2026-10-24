.setcpu "65816"
.segment "CODE"
.org $D6C2
map_control_0fd6c2:
    .byte $EB ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $0D ; distance low bit/count
