.setcpu "65816"
.segment "CODE"
.org $AE14
map_control_0dae14:
    .byte $EB ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $C2 ; same-value copy count/distance
