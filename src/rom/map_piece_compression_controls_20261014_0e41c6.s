.setcpu "65816"
.segment "CODE"
.org $41C6
map_control_0e41c6:
    .byte $EF ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $C1 ; same-value copy count/distance
    .byte $F1 ; progressive-copy count
    .byte $EF ; backreference distance high bits
    .byte $8F ; distance low bit/count
