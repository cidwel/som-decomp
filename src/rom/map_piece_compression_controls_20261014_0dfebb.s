.setcpu "65816"
.segment "CODE"
.org $FEBB
map_control_0dfebb:
    .byte $C2 ; same-value copy count/distance
    .byte $EB ; backreference distance high bits
    .byte $02 ; distance low bit/count
