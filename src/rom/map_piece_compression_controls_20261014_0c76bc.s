.setcpu "65816"
.segment "CODE"
.org $76BC
map_control_0c76bc:
    .byte $EB ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $EE ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $C1 ; same-value copy count/distance
