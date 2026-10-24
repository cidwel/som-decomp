.setcpu "65816"
.segment "CODE"
.org $5C09
map_control_0d5c09:
    .byte $E9 ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $C6 ; same-value copy count/distance
    .byte $EE ; backreference distance high bits
    .byte $82 ; distance low bit/count
