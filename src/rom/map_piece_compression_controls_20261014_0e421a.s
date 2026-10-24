.setcpu "65816"
.segment "CODE"
.org $421A
map_control_0e421a:
    .byte $EF ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $C1 ; same-value copy count/distance
    .byte $F1 ; progressive-copy count
