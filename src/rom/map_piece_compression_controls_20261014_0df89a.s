.setcpu "65816"
.segment "CODE"
.org $F89A
map_control_0df89a:
    .byte $F3 ; progressive-copy count
    .byte $E9 ; backreference distance high bits
    .byte $02 ; distance low bit/count
