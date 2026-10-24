.setcpu "65816"
.segment "CODE"
.org $5AE4
map_control_0c5ae4:
    .byte $C2 ; same-value copy count/distance
    .byte $ED ; backreference distance high bits
    .byte $8B ; distance low bit/count
    .byte $EE ; backreference distance high bits
    .byte $02 ; distance low bit/count
