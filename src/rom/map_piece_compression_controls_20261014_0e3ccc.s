.setcpu "65816"
.segment "CODE"
.org $3CCC
map_control_0e3ccc:
    .byte $EF ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $C1 ; same-value copy count/distance
    .byte $F1 ; progressive-copy count
    .byte $EB ; backreference distance high bits
    .byte $83 ; distance low bit/count
