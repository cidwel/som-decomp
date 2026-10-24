.setcpu "65816"
.segment "CODE"
.org $33FA
map_control_0f33fa:
    .byte $C3 ; same-value copy count/distance
    .byte $EB ; backreference distance high bits
    .byte $02 ; distance low bit/count
