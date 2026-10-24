.setcpu "65816"
.segment "CODE"
.org $5A7C
map_control_0c5a7c:
    .byte $EB ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $C4 ; same-value copy count/distance
    .byte $ED ; backreference distance high bits
    .byte $8B ; distance low bit/count
