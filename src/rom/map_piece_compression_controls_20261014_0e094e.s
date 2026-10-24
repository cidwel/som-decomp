.setcpu "65816"
.segment "CODE"
.org $094E
map_control_0e094e:
    .byte $F1 ; progressive-copy count
    .byte $C6 ; same-value copy count/distance
    .byte $EE ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $0A ; distance low bit/count
