.setcpu "65816"
.segment "CODE"
.org $8572
map_control_0d8572:
    .byte $CB ; same-value copy count/distance
    .byte $EA ; backreference distance high bits
    .byte $02 ; distance low bit/count
