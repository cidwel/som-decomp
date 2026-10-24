.setcpu "65816"
.segment "CODE"
.org $24EB
map_control_0e24eb:
    .byte $F2 ; progressive-copy count
    .byte $EE ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $C2 ; same-value copy count/distance
    .byte $EF ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $F3 ; progressive-copy count
