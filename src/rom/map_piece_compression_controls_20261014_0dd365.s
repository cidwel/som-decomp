.setcpu "65816"
.segment "CODE"
.org $D365
map_control_0dd365:
    .byte $D9 ; same-value copy count/distance
    .byte $D2 ; same-value copy count/distance
    .byte $EA ; backreference distance high bits
    .byte $02 ; distance low bit/count
