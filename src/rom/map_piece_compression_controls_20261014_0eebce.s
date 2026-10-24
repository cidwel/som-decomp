.setcpu "65816"
.segment "CODE"
.org $EBCE
map_control_0eebce:
    .byte $EB ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $C1 ; same-value copy count/distance
