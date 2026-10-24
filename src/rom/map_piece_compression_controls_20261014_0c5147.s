.setcpu "65816"
.segment "CODE"
.org $5147
map_control_0c5147:
    .byte $EE ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $E9 ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $C5 ; same-value copy count/distance
