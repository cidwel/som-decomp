.setcpu "65816"
.segment "CODE"
.org $53A5
map_control_0f53a5:
    .byte $EB ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $C1 ; same-value copy count/distance
