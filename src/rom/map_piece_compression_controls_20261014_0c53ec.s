.setcpu "65816"
.segment "CODE"
.org $53EC
map_control_0c53ec:
    .byte $C2 ; same-value copy count/distance
    .byte $EB ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $EF ; backreference distance high bits
    .byte $86 ; distance low bit/count
