.setcpu "65816"
.segment "CODE"
.org $38CE
map_control_0f38ce:
    .byte $C2 ; same-value copy count/distance
    .byte $EA ; backreference distance high bits
    .byte $02 ; distance low bit/count
